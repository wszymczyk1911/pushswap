*This project has been created as part of the 42 curriculum by wikszymc, djuja.*

# push_swap

## Description

`push_swap` sorts a stack of integers using only two stacks and a small set of allowed moves, aiming to do it in as few operations as possible. You hand it a list of numbers, it drops them into stack `a`, and it prints out the shortest sequence of moves it can find to leave `a` sorted in ascending order, smallest value on top.

The twist is that the program doesn't rely on a single sorting method. It ships with four different strategies and picks between them depending on how "disordered" the input is:

- **Simple** – an `O(n²)` approach, used for small or barely-shuffled stacks.
- **Medium** – an `O(n√n)` chunk-based approach for moderately mixed-up stacks.
- **Complex** – an `O(n log n)` approach for heavily shuffled stacks.
- **Adaptive** (default) – measures the disorder of the input first, then automatically hands the job to Simple, Medium, or Complex depending on how messy the stack is.

Disorder is a value between 0 and 1 that reflects how far the stack is from being sorted (0 = already sorted, 1 = worst possible order), computed by counting out-of-order pairs before any move is made. The adaptive strategy uses this score to decide: below 0.2 it treats the stack as nearly sorted and reaches for Simple, between 0.2 and 0.5 it uses Medium, and above 0.5 — where the input is essentially random — it falls back to the log-linear Complex sort so the operation count doesn't blow up.

A companion `checker` program (bonus) replays a sequence of moves against the original stack and confirms whether it actually ends up sorted, which is what we used to validate our own solvers during development.

## Instructions

Build everything with `make` from the project root; it pulls in `libft` and the custom `ft_printf` as dependencies:

```
make          # builds push_swap
make -C checker bonus   # builds the checker (bonus), if you want to validate sequences
make clean    # removes object files
make fclean   # removes object files and the binaries
make re       # fclean + all
```

Run it by passing the numbers to sort as arguments:

```
./push_swap 2 1 3 6 5 8
```

An optional flag lets you force a specific strategy instead of letting it decide automatically:

```
./push_swap --simple 5 4 3 2 1
./push_swap --medium 2 1 3 6 5 8
./push_swap --complex 2 1 3 6 5 8
./push_swap --adaptive 2 1 3 6 5 8   # same as omitting the flag
```

Add `--bench` to print sorting stats (disorder %, strategy used, total operation count, and a breakdown per operation type) to stderr, on top of the normal move list on stdout:

```
./push_swap --bench 2 1 3 6 5 8
```

Invalid input (non-integer arguments, duplicates, or numbers outside the integer range) prints `Error` to stderr. Running the binary with no arguments does nothing and just returns.

To check that a given sequence of moves genuinely sorts a stack, pipe `push_swap`'s output into the checker with the same numbers:

```
./push_swap 2 1 3 6 5 8 | ./checker/checker 2 1 3 6 5 8
```

## Available operations

`sa`, `sb`, `ss` (swap the top two of `a`, of `b`, or both at once), `pa`, `pb` (move the top of one stack to the top of the other), `ra`, `rb`, `rr` (rotate everything up by one, wrapping the top to the bottom), and `rra`, `rrb`, `rrr` (the reverse rotation).

## Contributions

- **wikszymc (Wiktoria)** — overall project structure, the stack/operation primitives (`sa`, `pa`, `ra`, `rra`, etc. and their `b`/combined variants), and the Simple and Medium sorting strategies.
- **djuja (Dawid)** — argument parsing and validation, the Complex sorting strategy, and the checker program.

Both of us reviewed and understand the full codebase, including the adaptive strategy and disorder metric, which were built jointly.

## Resources

- [Big-O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Insertion sort — Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
- [Merge sort — Wikipedia](https://en.wikipedia.org/wiki/Merge_sort)
- 42 push_swap subject document (provided with the project)

AI assistance was used sparingly, mainly to sanity-check edge cases in the rotation/argument-parsing logic and to help draft this README from the existing code and the project subject; every function in the repository was written, understood, and is defendable by us.
