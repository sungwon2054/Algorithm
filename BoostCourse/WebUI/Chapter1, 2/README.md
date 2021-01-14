# Chapter 1, Chapter 2

# 1. HTML 이해하기
## 1.1. HTML이란?
---
- Hyper Text Markup Language로 웹 페이지의 특정 부분과 연결할 수 있는 기능르 가진 텍스트 
- 정보를 구조적, 계층적으로 표현 가능 

## 1.2. HTML 문법
---

### 1.2.1 태그
``` 
<h1> Hello, HTML </h1>
```
- 태그 : HTML 태그들의 집합으로 기본적인 규칙 
     - ex) \<h1>, \</h1>
- 요소 : 내용을 포함한 태그 전체 
     - ex) \<h1>Hello, HTML\</h1>

### 1.2.2. 속성
 - 의미 : 태그에 대한 추가 정보나 태그의 동작이나 표현을 제어할 수 있는 설정 값
 - 여러 속성을 사용하기 위해 공백으로 구분해 사용한다
 - ex)  h1 태그의 id 값을 title로 설정

 ```html
<h1 id="title">Hello, HTML</h1>
```
   
### 1.2.3. 중첩
 - 태그 안에 다른 태그를 선언
 - 자식 태그는 항상 부모 태그 안에 있어야한다
 - ex)

```html
<h1 id="title">
    Hello, HTML
    <i>HTML</i>
</h1>
```

### 1.2.4. 빈 태그
 - 일반적인 태그(시작 태그, 종료 태그가 존재)가 아닌 시작 태그만 존재하는 태그
 - 브라우저가 직접 화면에 내용을 그려줌
 - 대표적으로 <img>, <input> 이 존재
 - ex)

```html
<input type="">
<br>
<img src="">
```

### 1.2.5. 공백
 - HTML은 기본적으로 두 칸 이상의 공백을 무시
 - 만약 2칸 이상 띄우고 싶다면?   
    __CSS에서 white-space속성을 pre-wrap으로 설정__

### 1.2.6. 주석
 - 화면에 노출하지 않고 메모의 목적이나 test 코드 실행시 사용
 -  사용방법 :  <!--  "contents "  -->
 - ex)

```html
<!-- <h1>Hello, HTML</h1> -->
```

## 1.3. HTML 기본구조?

```html
<!doctype html>
<html lang="ko">
    <head>
        <meta charset="UTF-8">
        <title>탭에 보이는 이름</title>
    </head>
    <body>
        <h1>Hello, HTML</h1>
    </body>
</html>
```

 - doctype : 이 문서가 어떤 버전으로 작성되었는지 의미    
__현재 코드는 html5으로 작성__
 - \<html> : lang 속성은 어느 언어로 작성되었는지 의미
 - \<head> : 문서 기본설정, 외부 스타일 시트 파일, js 파일을 연결
 - \<body> : 브라우저의 내용

# 2. HTML 태그
## 2.1 제목과 단락(h1~h6, p)
- 제목 태그   
 - \<h1>~\<h6>까지 존재
 - 숫자가 높을수록 큰 제목, 낮을수록 작은 제목

- 단락 태그
 - \<p>를 사용   
만약 개행을 하고 싶으면 \<br>사용

## 2.2 텍스트를 꾸며주는 요소
- \<b> : __글자 굵게__
- \<i> : *기울임*
- \<u> : 밑줄
- \<s> : ~~중간선~~


## 2.3 앵커 요소(a)

```html
<a href="http://naver.com/" target="_blank">네이버</a>
```
 - href 속성 : 목적지 URI
 - target 속성 : 
  - _blank : 새로운 창에 열어줌
  - _self : 현재 창에 열어줌

## 2.4 의미가 없는 컨테이너 요소(div, span)

- div : Division으로 웹 사이트의 전체적인 틀을 만들때 사용   
__블록 레벨 태그__(여러개 있을시 밑에 작성)

- span : (컴퓨터) 범위의 의미로 다방면으로 활용   
__인라인 레벨 태그__(여러개 있을시 한줄로 작성)

## 2.5 리스트 요소(ul, ol dl)

### 2.5.1 ul : unordered list   
ex)

```html
운동
<ul>
    <li>축구</li>
    <li>야구</li>
    <li>농구</li>
</ul>
```
 >운동
  - 축구
  - 야구
  - 농구

### 2.5.2 ol : ordered list   
ex) 

```html
라면 끓이기
<ol>
    <li>물 넣고 끓이기</li>
    <li>스프, 라면 넣기</li>
    <li>익을때까지 끓이기</li>
</ol>
```
>라면 끓이기
  1. 물 넣고 끓이기
  2. 스프, 라면 넣기
  3. 익을 때 까지 끓이기

### 2.5.3 dl : difinition/description list   
ex)

```html
<dl>
    <dt>HTML</dt>
    <dd>HyperText Markup Language</dd>
</dl>
```
 
>HTML   
   >>Hyper Text Markup Language 

## 2.6 이미지 요소(img)

```html
<img src="./images/pizza.png" alt="피자">
```
- src 속성 : 이미지 경로를 나타냄
  - 상대경로 : 현재 웹 페이지 기준으로 상대적인 이미지의 위치
  - 절대경로 : 실제 이미지가 위치한 곳의 전체 경로

 - alt 속성 : 이미지의 대체 텍스트를 나타냄

## 2.7 테이블 요소(table)

### 2.7.1 표의 구성요소
- \<table> : 표를 나타냄
- \<th> : 제목 셀을 나타냄
- \<tr> : 행을 나타냄
- \<td> :열을 나타냄
- ex)

```html
<table>
    <tr>
        <td>1</td>
        <td>2</td>
    </tr>
    <tr>
        <td>3</td>
        <td>4</td>
    </tr>
</table>
```

### 2.7.2 표의 구조와 관련된 태그
- \<caption> : 표의 제목
- \<thead> : 제목 그룹
- \<tbody> : 본문 그룹
- \<tfoot> : 바닥 그룹
- ex)

```html
<table>
    <caption>Title</caption>
    <thead>
        <!-- 제목 부분 -->
    </thead>
    <tbody>
        <!-- 본문 부분 -->
    </body>
    <tfoot>
        <!-- 바닥 부분 -->
    </tfoot>
</table>
```

### 2.7.3 표에 병합 되었을 때의 속성
- rowspan : 열 병합   
ex)

```html
<th rowspan="2"></th>
```

- colspan : 행 병합   
ex)

```html
<th colspan="2"></th>
```

## 2.8 폼 요소(form, input, select, textarea)
### 서버에 데이터를 전달하기 위한 요소
- input 태그의 placeholder 속성 : 입력하는 값의 양식을 표현

### 2.8.1 input 태그의 type 속성
- text : 아이디, 주소, 전화번호 등 단순 텍스트 입력시 사용
- password : 암호 입력할 때 사용
- radio : 여러 항목 중 1개만 선택시 사용(ex. 성별)
- checkbox : 여러 항목 중 다중 선택시 사용(ex. 취미) 
- file : 파일을 서버에 올릴 때 사용( ex. 사진)
- __submit : form의 값을 전송하는 버튼__
- reset : form의 값을 초기화하는 버튼
- image : 이미지를 삽입할 수 있는 버튼
- button : 기능이 없는 버튼

### 2.8.2 그 외의 태그1
- select : 선택 상자 (여러가지 항목 중 선택 가능)   
 - selected 속성 : 페이지 로드시 제일 먼저 선택되어 있음

- textarea : 여러 줄의 텍스트를 입력
 - cols 속성 : 가로 크기 조절
 - rows 속성 : 세로 크기 조절

- button : 버튼을 만들 때 사용
 - submit : form의 값을 전송
 - reset : form의 값을 초기화
 - button : 일반 버튼
 - __input과 다른점은 빈 태그가 아니며 좀 더 자유로운 스타일 표현 가능__

### 2.8.3 그 외의 태그2
- label : form 요소의 이름과 form 요소를 연결
- fieldset : 여러 개의 폼 요소를 그룹화
- legend : 폼 요소의 제목을 fieldset 내부에 작성
-  __form : form 내부의 요소들을 서버로 전송__
  - action 속성 : 서버의 주소
  - method 속성 : 데이터 전송 방식
     - get : 데이터 전송시 URI에 데이터를 파라미터로 전달
     - post : 데이터 전송시 body에 담아 데이터 전달
