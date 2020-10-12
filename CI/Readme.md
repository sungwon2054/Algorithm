# CI
 - **지속적 통합**이라는 의미로 
소프트웨어의 **질적 향상**과 소프트웨어 배포 시간을 줄이는데 초점이 맞춰져있다. 

 - 프로젝트시 개발자들이 개발을 진행하며 코드를 통합하는데 오래걸릴수 있어 테스트를 거쳐 **통합을 편리**하게함
 <img src="https://pepgotesting.com/wp-content/uploads/2015/02/CI.png">
 
 [이미지출처](https://pepgotesting.com/continuous-integration/)
  
## CI의 종류 
 - Circle CI : 
   + 구동 환경 : Cloud, On-prmise
   + 서비스 형태로 제공, 트래비스와 같이 저장소 단위로 빌드
   + 환경요소를 docker를 통해 생성하고, 작업 후에 작업환경을 삭제
 - Jenkins CI : 
   + 구동 환경 : Cloud
   + 설치형 서비스로 설치와 관리가 매우 어려움
   + 많은 회사에서 주로 사용
 - Travis CI : 
   + 학생은 무료지만 기업은 유료고 가격이 꽤 비쌈
   + 빌드에 필요한 컨테이너를 필요할 때만 사용
   
 - buddybuild : 
   +  travis 보다 빌드속도 빠르며, 저장소 단위가 아닌 애플리케이션 프로젝트를 하나의 단위로 사용
## CI의 실행 방법
  ```
  version: 2.1
> circle ci의 버전
orbs:
> orb 호출하여 작업을 실행시킬 환경과 버전을 가져옴
  node: circleci/node@3.0.0

jobs:
 > 자동화 시킬 것을 작업
  build:
    working_directory: ~/dir_name
    > orb 개발 환경에서 작업에 필요한 환경을 정의
    executor: node/default
    steps:
      - checkout
      > npm을 설치
      - node/install-npm
      > orb 환경에 사용할 패키지 설치
      - node/install-packages:
          app-dir: ~/dir_name
          cache-path: node_modules
          override-ci-command: npm i
      # Save workspace for subsequent jobs (i.e. test)
      - persist_to_workspace:
          root: .
          paths:
            - .

  test1:
    docker:
      > 작업할 container 실행
      - image: cimg/node:current
    steps:
      > test 할 내용
      - attach_workspace:
          at: . 
      - run:
      > 실행 할 명령
          name: check
          command: bash ./.circleci/check.sh test-content
      - run:
          name: lint test
          command: npm run test-script
  
     
workflows:
> jobs를 어떻게 동작할지 정의
  version: 2
  build_and_test:
    jobs:
    > jobs를 실행
      - build
      - test1:
          requires:
          > test1 수행 전에 해야 할 일
            - build
      
  ```
## 용어 정리
Cloud: 하나의 물리적 서버를 나누어 여러개의 가상서버로 사용

On-prmise : 기업의 서버를 클라우드가 아닌, 자체적으로 보유한 전산실 서버에 직접 설치한 것을 의미
