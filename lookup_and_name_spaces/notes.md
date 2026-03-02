When an identifier is encountered in a C program, a lookup is performed to locate the
declaration that introduced that identifier and is currently in scope.

C allows more than one declaration for the same identifier to be in scope simultaneously if
these identifiers belong to different categories, called name spaces:
1) label name space: all identifiers declared as labels.

2) tag names: all identifiers declared as names of structs, unions and enumerated types. Note
that all three kinds of tags share one name space

3) Member names: all identifiers declared as members of any one struct or union. Every struct
and union introduces its own name space of this kind.

4) Global attribute name space: attribute tokens defined by the standard or implementation-
defined attribute prefixes.

5) non-standard attribute names: attribute names following attribute prefixes. Each attribute
prefix has a separate name space for the implementation-defined attributes it introduces.

6) all other identifiers, called ordinary identifiers to distinguish from (1 - 5)(function
names, object names, typedef names, enumeration constants).


At the point of lookup, the name space of an identifier is determined by the manner in which
it is used:
1) Identifier appearing as the operand of a goto statement is looked up in the label name space.

2) Identifier that follows the keyword `struct`, `union`, or `enum` is looked up in the tag
space.

3) Identifier that follows the member access or memebr access through pointer operator is looked
up in the name space of members of the type determined by the left-hand operand of the member
access operator.

4) Identifier that directly appears in an attribute specifier ([[...]]) is looked up in the
global attribute name space.

5) Identifier that follows the `::` token following an attribute prefix is looked in the 
name space introduced by the attribute prefix.

6) all other identifiers are looked up in the name space of ordinary numbers.


### Notes
the names of macros are not part of any name space because they are replaced by the 
preprocessor prior to semantic analysis.

It's common practice to inject struct/union/enum names into the name space of the ordinary 
identifiers using a typedef declaration:
```
struct A { }; 		// introduces the name A in tag name space
typedef struct A A; 	// first, lookup for A after "struct" finds one in tag name space
			// then introduces the name A in the ordinary name space
struct A* p;		// OK, this A is looked up in the tag name space
A* q;			// OK, this A is lookup up in the ordinary name space
```



A well known example of the same identifier being used across two name spaces is the identifier
`stat` from the POSIX header sys/stat.h. It names a function when used as an ordinary identifier
and indicates a struct when used as a tag.

Unlike in C++, enumeration constants are not struct members, and their name space is the name
space of ordinary identifiers, and since there is no struct in C, their scope in which the
struct declaration appears:

```
struct tagged_union {
	enum {INT, FLOAT, STRING} type;
	union {
		int integer;
		float floating_point;
		char *string;
};
} tu;

tu.type = INT // OK in C, error in C++
```
