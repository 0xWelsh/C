### Comments
comments serve as a sort of in-code documentation. When inserted into a program, they are
effectively ignored by the compiler, they are solely intended to be used as notes by the 
humans that read source code.

## Syntax
`/* comment */`
`// comment`

## Notes
because comments are removed before the preprocessor stage, a macro cannot be used to form
a comment and an unterminated C-style comment doesn't spill over from an #include'd file.

```
/* An attempt to use a macro to form a comment. */
/* But, a space replaces characters  "//".      */
#ifndef DEBUG
	#define PRINTF //
#else
	#define PRINTF printf
#endif
...
PRINTF("Error in file %s at line %i\n", __FILE__, __LINE__);
```

besides commenting out, other mechanisms used for source code exclusions are:

```
#if 0
	puts("this will not be compiled");
	/* no conflict with C-style comments */
	// no conflict with c++ style comments
#endif
```

and

```
if(0) {
	puts("this will be compiled but not executed");
	/* no conflict with C-style comments */
	// no conflict with C++ style comments
}
```

the introduction of // comments in C99 was a breaking change in some rare circumstances:
```
a = b //*divisor:*/ c
+ d; /* C89 compiles a = b / c + d;
	C99 compiles a = b + d; */
```

