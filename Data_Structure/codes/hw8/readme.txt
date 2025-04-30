1. 구현한 파일은 Ad_List.h, Ad_Matrix.h이고,
필요한 파일은 Stack, Queue, List에 관한 헤더 파일이다.

Ad_List의 경우 List를 두개 겹쳐놨다.
Graph라는 리스트 안에 Vertex라는 리스트를,
Vertex라는 리스트 안에 Edge를 넣어놨다.



2. main2.c 파일을 실행시킨다.
사용하고픈 방식에 따라 Ad_List.h, Ad_Matrix.h 중 하나를 include해서 사용한다.
같은 폴더 내에 있는 텍스트 파일을 읽어 그래프를 생성한다.
텍스트 파일 형식은 다음과 같다.

A
B C
D E

(A를 시작점으로
B->C edge 생성
D->E edge 생성
필요 시 각각의 vertex 생성)
파일 형식이 맞지 않으면 오류가 난다.





3. 구현한 파일은 Ad_Matrix3.h이고,
필요한 파일은 List에 관한 헤더 파일이다.



4. main4.c 파일을 실행시킨다.
같은 폴더 내에 있는 텍스트 파일을 읽어 그래프를 그린다.
텍스트 파일 형식은 다음과 같다.

A
B C 2
D E 4

(A를 시작점으로
B<->C의 크기가 2인 edge 생성
D<->E의 크기가 4인 edge 생성
필요 시 각각의 vertex 생성)
파일 형식이 맞지 않으면 오류가 난다.