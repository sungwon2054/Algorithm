# Chapter3, Chapter4
<br>

# 3. 콘텐츠모델, 시멘틱마크업, 블록 & 인라인

<br>

## 3.1. 콘첸츠모델
<img src="https://media.prod.mdn.mozit.cloud/attachments/2012/07/09/3704/07b3e5bb546840a09bb35d45b36009a6/Content_categories_venn.png" height="200">

#### 3.1.1. Metadata
 - 스타일, 동작 설정, 다른 문서와의 관계 등의 정보를 포함
 - 주로 head의 위치
#### 3.1.2. Flow
 - 문서의 자연스러운 흐름에 의해 배치
#### 3.1.3. Sectioning
 - 문서의 구조와 관련   
 ex) article, aside, nav, section
 
#### 3.1.4. Heading
 - 제목 태그   
 ex) h1, h2, h3, h4, h5, h6
 
#### 3.1.5. Phrasing
 - 텍스트 또는 텍스트를 꾸며주는 문단 내부 레벨   
 ex)a, i, span, textarea 등
 
#### 3.1.6. Embedded 
 - 외부 콘텐츠를 표현하는 요소   
 ex) audio, canvas, video, img
 
#### 3.1.7. Interative
 - 사용자와 상호작용을 하는 요소
 ex) __form요소__ 
 
<br>
 
## 3.2. 시멘틱 마크업
 - 기계(컴퓨터, 브라우저)가 잘 이해할 수 있도록 함

#### 3.2.1 시멘틱 마크업 하기
 - \<strong> : 중요한 (굵은)
 - \<em> : 강조하는 (기울임)
 - \<ins> : 새롭게 추가된(밑줄친)
 - \<del> : 삭제된(중간선)
 
#### 3.2.2 html5에 추가된 시멘틱 마크업
 - article : 문서, 페이지, 어플리케이션 등 따로 독리접으로 구분해 배포하거나 재사용   
 ex) 게시판, 뉴시기사 등
 - detail : 말 그대로 "열림" 상태일 때만 내부 정보 공개
 - header : 소개 및 탐색에 도움을 줌   
 ex) 제목, 로고, 검색 폼 등
 - main : 중요 콘텐츠 표시
 - footer : 기획 콘텐츠, 루트 등을 나타냄   
 ex) 작성자, 저작권 정보, 문서 등
 - section : 문서의 독립적인 구획   
 ex) 제목
  
<br>

## 3.3. 블록 & 인라인
- block level 요소 : 한 줄에 하나의 요소   
ex) div, ul, li
- inline level 요소 : 한 줄에 여러개   
ex) span, i, img
<img src="https://lh3.googleusercontent.com/proxy/R-pr6E0i-Naii3YU0NDpDN0BHenZstMMO7haZ8FCQeDzuIREsiQQCjzCDIYXjCoRs-AcDjtjbxLCo-yXWR4weaRzGfAfqJJNuy7yBznTzOcfM8wv2bTht_4xEt5by16LM3tuXJAOnwMlprXlb46R7A" height="200">
