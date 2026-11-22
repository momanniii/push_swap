*This activity has been created as part of the 42 curriculum by wgharaib, abalmoma.*

# Push_swap

## Description

**Push_swap** is an algorithm project: sort a list of integers using two stacks (`a` and `b`) and a very limited set of operations, while printing the **smallest possible list of operations** on the standard output.

At the start, stack `a` holds the integers given as arguments (no duplicates, first argument on top) and stack `b` is empty. The goal is to finish with `a` sorted in ascending order (smallest number on top) and `b` empty.

The real goal of the project is to experience **algorithmic complexity**: the cost of an algorithm is measured in the **number of Push_swap operations it generates**, not in CPU time. This project therefore embeds four strategies in a single binary:

| Strategy | Selector | Complexity (in operations) | Technique |
|---|---|---|---|
| Simple | `--simple` | O(n²) | Selection sort (min extraction) |
| Medium | `--medium` | O(n√n) | Chunk-based sort (≈√n chunks) |
| Complex | `--complex` | O(n log n) | LSD binary radix sort |
| Adaptive | `--adaptive` (default) | depends on the disorder | Picks one of the three above from the measured **disorder** |

The program also has an optional **benchmark mode** (`--bench`) that reports the disorder, the strategy used and the number of operations of each type.

### Allowed operations

| Op | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | rotate `a` / `b` / both: the first element becomes the last |
| `rra` / `rrb` / `rrr` | reverse rotate `a` / `b` / both: the last element becomes the first |

## Instructions

### Compilation

```bash
make          # builds libft, ft_printf and ./push_swap (flags: -Wall -Wextra -Werror)
make clean    # removes the object files
make fclean   # removes the object files and the binaries
make re       # fclean + all
```

The Makefile does not relink: running `make` twice does nothing the second time.

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers...>
```

- The integers can be separate arguments, one quoted string, or a mix: `./push_swap 3 2 1`, `./push_swap "3 2 1"`, `./push_swap "3 2" 1`.
- The strategy selector is optional. **`--adaptive` is the default.**
- A forced selector (`--simple`, `--medium`, `--complex`) is always honoured, whatever the input size or disorder.
- Flags can be given in any order, before the numbers.
- Operations are printed on **stdout**, one per line.
- With no arguments the program prints nothing.

### Benchmark mode (`--bench`)

The report is printed on **stderr** after sorting, and only when the flag is present. The operations on stdout are unchanged.

```bash
$ ./push_swap --bench --adaptive 4 67 3 87 23 2> bench.txt | wc -l
13
$ cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 0 rb: 2 rr: 0 rra: 0 rrb: 1 rrr: 0
```

With a forced selector, the strategy line shows that strategy (for example `Simple / O(n^2)`, `Medium / O(n√n)`, `Complex / O(n log n)`). In adaptive mode it shows `Adaptive` together with the complexity class of the regime that was selected.

### Errors

In case of error the program prints `Error` followed by a newline on **stderr** and exits with a non-zero status. Errors are:

- an argument that is not an integer (letters, a lone `+` or `-`, an empty string, ...);
- an integer outside the range of a 32-bit `int` (`-2147483648` to `2147483647`), including very long numbers;
- duplicate values (`0` and `-0` are duplicates);
- an unknown option (for example `--foo`) or options without any number.

```bash
$ ./push_swap --adaptive 0 one 2 3
Error
$ ./push_swap --simple 3 2 3
Error
```

### Testing

With the checker provided by the school:

```bash
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt) | wc -l
```

We also used our own test script (random inputs, every strategy, error cases, `--bench` consistency, leak checks with AddressSanitizer). It is not part of the submission.

## Algorithms

### Preliminary step: index normalization

Radix sort and chunk sort work on ranks, not on raw values. Before sorting, every node gets an `index` equal to its rank among all values (0 for the smallest, n-1 for the largest):

1. copy the values into an array;
2. sort the array with a merge sort — O(n log n) time, O(n) temporary memory;
3. give each node the position of its value in the sorted array by binary search — O(log n) per node.

This is local computation: it generates **no** Push_swap operation, and its temporary memory is freed immediately.

### Disorder metric

The disorder is the ratio between the number of **inversions** (pairs where a bigger number appears before a smaller one) and the number of pairs:

```
disorder = mistakes / total_pairs        (0 = sorted, 1 = reverse order)
```

It is computed exactly as described in the subject (double loop over all pairs, O(n²) time and O(1) memory) and **before any move**. It is displayed with two decimals by `--bench`. A random permutation has an expected disorder of about 0.5 (we measure values such as 49.93 % or 50.10 % on random inputs).

### Simple strategy: selection sort — O(n²)

*Idea:* repeatedly extract the minimum.

1. While `a` is not empty: find the smallest element, rotate `a` until it is on top, `pb`.
2. Then `pa` every element of `b` back. Since the smallest values were pushed first, they end up in the right order on `a`.

*Complexity (operations):* each of the n extractions needs at most n-1 rotations and one `pb`, then n `pa`: at most n(n-1) + 2n = **O(n²)**. *Space:* O(1) beyond the stacks.

*Why it is here:* it is the baseline required by the subject, it is easy to prove correct, and it has no setup cost, which makes it reasonable for tiny stacks.

### Medium strategy: chunk sort — O(n√n)

*Idea:* split the ranks into windows of about √n elements, push the elements of each window to `b` in a way that leaves `b` almost sorted, then pull them back from the biggest to the smallest.

Let `c = ⌊√n⌋ × 3/2` (at least 1) be the window size, and `pushed` the number of elements already moved to `b`.

*Phase 1 — push to b.* For each element on top of `a` (by rank):
- rank ≤ `pushed`: `pb` then `rb` (small elements go to the bottom of `b`);
- rank ≤ `pushed + c`: `pb`;
- otherwise: `ra` (it is not in the current window yet).

*Phase 2 — pull back.* While `b` is not empty: find the element with the biggest rank, bring it to the top with `rb` or `rrb` (whichever direction is shorter), then `pa`. `a` is built from the biggest to the smallest, so it ends sorted.

*Complexity (operations):*
- Every element that is pushed satisfies `rank ≤ pushed + c`. Among the ranks `0..pushed+c`, exactly `c+1` are still in `a`, and all of them are pushed during the next pass over `a`. So each pass pushes at least `c+1` elements and there are at most `n/(c+1) + 1 = O(√n)` passes. A pass costs at most `n` operations, so phase 1 costs **O(n√n)**.
- Take any rank `m` that was pushed when `pushed = p`. Then `m ≤ p + c`, and at most `c` elements with a smaller rank can be pushed after it (a counting argument on the ranks `< m`). So when `m` is extracted, only O(c) elements lie between it and the nearest end of `b`: each extraction costs O(√n) rotations and phase 2 costs **O(n√n)** (informal argument).
- Total: **O(n√n)**. *Space:* O(1) beyond the stacks.

*Measured:* about 0.45 to 0.57 × n√n operations on random inputs (see the table below).

### Complex strategy: LSD radix sort — O(n log n)

*Idea:* sort the ranks bit by bit, from the least significant bit to the most significant one.

For each bit `b` from 0 to ⌈log₂ n⌉ - 1, look at the n elements of `a` once: if bit `b` of the rank is 0, `pb`; otherwise `ra`. Then `pa` everything back. After the pass for bit `b`, the elements are sorted by their lowest `b+1` bits (the pass is stable), so after the last bit `a` is sorted.

*Complexity (operations):* each pass costs n operations on `a` plus at most n `pa`, i.e. at most 2n; there are ⌈log₂ n⌉ passes, so at most **2n⌈log₂ n⌉ = O(n log n)**. *Space:* O(1) beyond the stacks (the ranks are already stored in the nodes).

The number of operations only depends on n, not on the order of the input: 1084 for 100 numbers and 6784 for 500 numbers.

### Adaptive strategy

The adaptive strategy measures the disorder first, then chooses the technique:

| Disorder | Regime | Technique | Complexity |
|---|---|---|---|
| `< 0.2` | low | selection sort | O(n²) |
| `0.2 ≤ d < 0.5` | medium | chunk sort | O(n√n) |
| `≥ 0.5` | high | radix sort | O(n log n) |

Additionally, **stacks with fewer than 5 numbers always use the simple strategy**, whatever their disorder.

*Rationale for the thresholds.* The subject imposes the complexity target of each regime and the boundaries 0.2 and 0.5, so we use them as they are. A few remarks justify them in practice:
- a disorder of 0.5 is what a random permutation gives on average, so the 0.5 boundary splits the random inputs between the medium and the high regime;
- below 0.2, at most one pair in five is inverted: the stack is close to sorted and a simple algorithm is enough;
- for very small stacks (n < 5) the set-up of chunks or radix passes brings nothing, so we always use the simple strategy.

*Complexity argument.* The disorder is computed once, before any move, in O(n²) local comparisons (no operation generated). Then exactly one strategy runs, so the cost in operations is the cost of that strategy: O(n²), O(n√n) or O(n log n) depending on the regime. The additional memory is the same as the chosen strategy (O(1) beyond the stacks, plus the temporary O(n) array of the normalization step).

### Summary

| Strategy | Operations (upper bound) | Extra space | Notes |
|---|---|---|---|
| Normalization | none (local) | O(n) temporary | merge sort + binary search |
| Disorder | none (local) | O(1) | O(n²) comparisons |
| Simple | O(n²) | O(1) | n extractions |
| Medium | O(n√n) | O(1) | about 1.5√n per chunk |
| Complex | 2n⌈log₂ n⌉ = O(n log n) | O(1) | independent of the order |
| Adaptive | one of the above | as the chosen one | thresholds 0.2 / 0.5, n < 5 → simple |

### Measured performance

Measured on random permutations (several runs), counting the operations on stdout:

| Input | `--medium` | `--complex` | default (adaptive) |
|---|---|---|---|
| 100 numbers | about 575 | 1084 | about 870–980 (worst 1084) |
| 500 numbers | about 5050 | 6784 | about 6000–6450 (worst 6784) |

Subject targets: 100 numbers — pass < 2000, good < 1500, excellent < 700; 500 numbers — pass < 12000, good < 8000, excellent < 5500. The default mode therefore reaches the **good** level. The adaptive mode picks the medium strategy (excellent on its own) or the radix strategy (good) for about half of the random inputs each, because random inputs have a disorder close to 0.5.

## Technical choices and limits

- **No global variable.** The operation counters used by `--bench` are `static` variables inside functions of `ft_bench.c` (they are not globals). Every operation is printed through `ft_print_op`, which also counts it.
- **`ss`, `rr`, `rrr`** execute both moves silently (`do_swap`, `do_rotate`, `do_reverse_rotate`) and print **one** line.
- **Overflow-safe parsing.** `ft_atol` stops as soon as the value is out of the 32-bit range, so very long numbers cannot wrap around.
- **Complexity is measured in operations**, as required by the subject, not in CPU time.
- **Possible improvements:** the simple strategy does not exploit the existing order of the stack (it could stop as soon as the rest of `a` is already sorted); the radix strategy always does the same number of passes; neither `ss`, `rr` nor `rrr` is used by the strategies yet, although they could merge two operations into one.

## Project structure

| File | Role |
|---|---|
| `main.c` | entry point, argument validation, duplicate check, sorting and `--bench` report |
| `ft_flags.c` | parsing of `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench` |
| `ft_parsing.c`, `utils.c`, `utils2.c` | parsing of the numbers (`ft_split`, `ft_atol`), list helpers, memory freeing |
| `index_normalization.c`, `merge_sort.c` | rank computation (merge sort + binary search) |
| `ft_disorder.c` | disorder metric |
| `ft_simple_strategy.c` | selection sort |
| `ft_medium_strategy.c` | chunk sort |
| `radix_sort.c` | radix sort |
| `ft_adaptive_strategy.c` | choice of the strategy from the disorder |
| `ft_bench.c`, `ft_bench_print.c` | operation counters and `--bench` report |
| `ft_op_helper.c` | silent swap / rotate / reverse rotate used by the operations |
| `ft_push_a.c`, `ft_push_b.c`, `ft_swap_*.c`, `ft_rotate_*.c`, `ft_reverse_rotate_*.c` | the 11 Push_swap operations |
| `libft/`, `ft_printf/` | our libft and ft_printf, compiled by their own Makefiles |


## Contributions

| Learner | Contributions |
|---|---|
| wgharaib | **[TODO: describe what this learner did]** |
| abalmoma | **[TODO: describe what this learner did]** |

Both learners can explain every part of the code.

## Resources

### References

- *Push_swap* subject, version 1.2 (42).
- T. H. Cormen, C. E. Leiserson, R. L. Rivest, C. Stein, *Introduction to Algorithms* — chapters on sorting, linear-time sorting (radix sort) and asymptotic notation.
- D. E. Knuth, *The Art of Computer Programming*, volume 3: *Sorting and Searching*.
- Wikipedia: [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation), [Radix sort](https://en.wikipedia.org/wiki/Radix_sort), [Selection sort](https://en.wikipedia.org/wiki/Selection_sort), [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)), [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm).

### Use of AI

We used an AI assistant (Claude, by Anthropic) as a helper, not as a replacement for our own work. It was used for:

- **Debugging and explanations:** understanding compiler errors (incompatible pointer types between our stack type and `t_list`, an unused-value error caused by the operator precedence in `*total_pairs++`, function declaration order in `main.c`, a missing structure member).
- **Reviewing the code against the subject:** it pointed out a missing source file in the Makefile, `ss`/`rr`/`rrr` printing several lines for one operation, and the integer wrap-around of very long numbers in `ft_atol`.
- **The `--bench` mode and the flag parsing:** it proposed the design (an operation counter fed by a single print function, a report on stderr) and explained the steps, and we implemented and tested them.
- **Algorithm discussions:** the direction of the selection sort (extracting the minimum), how the chunk sort and the radix sort behave, and the complexity arguments above.
- **Testing:** a Python test script (random inputs, every strategy, error cases, `--bench` consistency) and an AddressSanitizer run to look for leaks. These scripts are not submitted
- **Documentation:** a first draft of this README, which we reviewed and corrected.

Every suggestion was tested against the examples of the subject and against our own tests before we kept it, and both of us can explain the code.
