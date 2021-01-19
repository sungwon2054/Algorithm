# Chapter7, 8
<br>

# 7. 레이아웃
## 7.1.속성
### 7.1.1 display
```css
display: value;
```
- none : 요소가 화면에 나오지 않음
- inline : inline level 요소처럼 렌더링
- block : block level 요소처럼 렌더링
- inline-block : inline level 요소처럼 렌더링되지만 block level 성질을 가짐

#### display와 box model의 관계
| display | width | height | margin | padding | border |
|---|:---:|---:|---:|---:|---:|
|block | O | O | O | O | O |
|inline | X | X | 좌/우 | 좌/우 | 좌/우 |
|inline-block| O | O | O | O | O |

<br>

### 7.1.2. visibility 
- 요소의 화면 표시 여부
```css
visibility: visible | hidden | collapse | initial | inherit;
```
- visible : 화면에 표시
- hidden : 표시되지않음(공간차지)
- collapse : 경계를 무시하고 숨김(테이블 요소만 적용)

##### display:none VS visibility:hidden
display는 아예 없어짐, visibility는 공간은 차지함

### 7.1.3. float
- 요소를 보통의 흐름에서 벗어나게 시킬지 지정하는 속성
- 특징    
  1. 요소를 보통의 흐름에서 벗어나 띄어지게 함
  2. 주변 텍스트나 인라인 요소가 주위를 감싸는 특징
  3. 대부분의 요소에 display 값을 block으로 지정(예외: inline-table, flex)
```css
float: none | left | right | initial | inherit;
```
- none : float 시키지 않음
- left : 좌측으로 float
- right : 우측으로 float

### 7.1.4. clear
- floating 된 요소의 영향에서 벗어나 다음 행으로 이동
```css
clear: none | left | right | both | initial | inherit;
```
- none : 양쪽으로 floating 요소를 허용
- left : 왼쪽으로 floating 요소를 허용하지 않음
- right : 오른쪽으로 floating 요소를 허용하지 않음
- both : 양쪽으로 floating 요소를 허용하지 않음   
__꼭 block-level 요소만 적용__

### 7.1.5. position & offset
 1. position
  - 요소를 원하는 곳으로 이동시켜줌
  ```css
  position: static | absolute | fixed | relative | sticky | initial | inherit;
  ```
  - static : normail-flow에 따라 배치되며 offset값 적용 안됨
  - absolute : 부모 기준으로 offset에 따라 배치   
  (부모의 position값이 static이 아닐 때 까지 거슬러 올라가 기준으로 삼음)
  - fixed : 화면 스크롤에 관계 없이 항상 정해진 위치
  - relative : offset에 따라 배치
  
2. offset
```css
top|bottom|left|right: auto|length|initial|inherit;

ex)
top: 50%;
left: 10px;
bottom: -10px;
right: auto;
```

### 7.1.6. z-index
- 요소가 겹치는 순서를 지정
- 특징   
  1. position이 static이 아닌 경우 지정 가능
  2. 순서 값이 없을 경우 생성순서에 따라 쌓임
  3. 부모 z-index 값이 있을 경우 부모 안에서만 의미 있음
  4. 큰 값이 가장 앞쪽
```css
z-index: auto | number | initial | inherit;
```
- auto : 쌓임 순서를 부모와 동일하게 설정
- number : 해당 수치로 쌓임 순서 설정

<br>

# 8. 미디어쿼리
## 8.1. 미디어쿼리 & 미디어타입
   1. 미디어쿼리 : 미디어 매체에 따라 다른 스타일을 적용할 수 있게 해줌   
   (미디어매체 : 모니터, 스크린 매체, 스크린 리더기 등)   
   - 동일한 웹 페이지를 다양한 환경의 사용자들에게 최적화된 경험 제공
   2. 미디어타입 : CSS2에서 다른 스타일을 적용할 수 있게 해줌   
   (미디어타입을 확장 -> 미디어쿼리)

## 8.2 미디어 타입 & 미디어 특성
- @media(at media)
  - 논리적으로 평가되어 참이면 스타일 규칙을 적용
  - 미디어타입   
    - all, print, screen을 주로 사용
  - 미디어특성   
    - width : 브라우저 창의 너비를 표현
    - orientation : 미디어가 세로모드, 가로모드 구별

```css
@media mediaqueries { /* style rules  */ }
```

## 8.3 Syntax
### 8.3.1. Syntax 세부 설명
```css
media_query_list
 : S* [media_query [ ',' S* media_query ]* ]?
 ;
media_query
 : [ONLY | NOT]? S* media_type S* [ AND S* expression ]*
 | expression [ AND S* expression ]*
 ;
expression
 : '(' S* media_feature S* [ ':' S* expr ]? ')' S*
 ;
```
- [a] : a가 나올 수도 있고, 나오지 않을 수도 있음
- a|b : a or b 중 선택
- a? : a가 0번 or 1번 나올 수 있음
- a* : a가 0번 or 여러번 나올 수 있음

### 8.3.2. Syntax 정리
- media_query_list : 여러개의 미디어 쿼리로 이루어진 리스트로 작성 가능
- media_query :    
  - A형태 :   
    - 미디어 타입에 and를 붙여 미디어 표현식을 붙임
    - 미디어 타입 앞에는 Only 또는 Not 키워드가 나옴
    - 미디어 표현식은 단독 타입으로 사용 가능
  - B형태 : 
    - 미디어 타입 없이 바로 표현식이 나올 수 있음
    - 미디어 표현식은 and로 계속 나올 수 있음
- expression :    
  - 미디어 표현식은 괄호로 감싸며, 특성이름과 해당 값으로 이루어짐

ex)
```css
@media screen { ... }
    /* : 미디어 타입이 screen이면 적용 */

@media screen and (min-width: 768px) { ... }
    /* : 미디어 타입이 screen이고 width가 768px 이상이면 적용 */

@media (min-width: 768px) and (max-width: 1024px) { ... }
    /* : width가 768 이상 1024 이하 */

@media (color-index){}
    /* : 미디어 장치가 color-index를 지원시 적용 */

@media screen and (min-width: 768px), screen and (orientation: portrait){}
  /*
    : 쉼표로 연결된 미디어 쿼리 중 하나라도 참이면 적용
  */

@media not screen and (min-width: 768px){}
  /*
    : not 키워드는 하나의 media_query 전체를 부정합니다.
    : (not screen) and (min-width: 768px) 잘못된 해석!
    : not (screen and (min-width: 768px)) 올바른 해석!
  */
```

### 8.3.3. 실습
<br>

#### 8.3.3.1 실습 1

```css
@media (max-width: 767px) {
	body { background-color: gold; }
}
@media (min-width: 768px) and (max-width: 1024px) {
	body { background-color: lightblue; }
}
@media (min-width: 1025px) {
	body { background-color: lightpink; }
}
```

- 뷰포트 크기에 따른 배경색 지정

<br>

#### 8.3.3.2. 실습 2   

```css
@media print {
	a { text-decoration: none; }
	a:after { display: inline; content: '(' attr(href) ')'; }
}
```

- 프린트시 content 뒤에 url이 나오고 밑줄(하이퍼링크)이 사라짐