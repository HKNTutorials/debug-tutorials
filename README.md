HKN debugging tutorials

# Problems
- memory-intro's [linked list
  example](https://github.com/HKNTutorials/memory-intro/blob/master/reverselist.c)
- Quine-McCluskey (boolean expression minimization)
- malloc implementation
- 391-style low-level "what does this do?"
- simple parser (regex perhaps)
- a pthread example (maybe)

# Workflows

## problem
- write problem
- write some starter tests in CuTest
- write solution and commit to solutions branch
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
- use [CuTest](http://cutest.sourceforge.net/) (C unit testing framework) to
  write tests
- maintain a `solutions` branch with all passing tests; manually keep master
  merged into `solutions`

# Desirable features
- code and solution stay in sync
- deliver code with solution somewhat hidden
- make solution available with some work / with our help
