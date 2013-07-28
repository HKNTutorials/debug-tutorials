HKN debugging tutorials

# Workflows

## problem
- write problem (how?)
- write test to check solution (how?)
- write solution to tutorial (how?)
- write slides explaining this problem
- write slides explaining solution

## tutorial
- some intro slides
- a collection of problems

# Technical details (work in progress)
- [remark](http://github.com/gnab/remark) for creating HTML slideshows from
  Markdown
- [GitHub releases](https://github.com/blog/1547-release-your-software) for
  packaging tutorials after a build
- avoid a complicated build process for 391 tutorials with inline asm: saves on
  maintenance effort and teaches syntax
- use simple `make` on the client:
  - teaches good use of `make`
  - teaches value of recompiling often (rather than us providing some sort of
    auto-runner)
  - will want to hide some complexity of compiling slides from users (to
    prevent random dependencies from leaking in)
- use `gtest`, with some hooks for C: link against our C++ wrapper and the
  `gtest` library, producing either a `gtest` or customized test binary
- maintain a `solutions` branch with all passing tests; manually keep master
  merged into `solutions`

# Desirable features
- code and solution stay in sync
- deliver code with solution somewhat hidden
- make solution available with some work / with our help
