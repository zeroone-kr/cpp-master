## lambda function

- f(x,y) = x +y => (x, y) -> x + y 이렇게 람다 대수에서 표현
- (( x, y ) => x+y)(2, 3)
- simple version: \[ captures \] ( params ) specs:optional { body }
- [captures](https://medium.com/@dpthegrey/explain-difference-between-formal-and-actual-parameter-with-example-26f63e7560bb): \[x\], \[&x\], \[=\], \[&\]
- If caputres is [] : 아무것도 캡쳐 안함
- If caputres is [&a, b] : a 는 레퍼런스로 캡쳐하고 b 는 (변경 불가능한) 복사본으로 캡쳐
- If caputres is [&] : 외부의 모든 변수들을 레퍼런스로 캡쳐
- If caputres is [=] : 외부의 모든 변수들을 복사본으로 캡쳐
- The sepcs:optional is automatically inferred through return statement
- can be used with algorithm function
