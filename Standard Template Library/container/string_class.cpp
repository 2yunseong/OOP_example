#include <iostream>
#include <string>

/* 출처: https://ldgeao99.tistory.com/220 */

using namespace std;

int main()
{
string compare_string = "abcde";
string compare_string2 = "abced";
string compare_string3 = "ccccc";

//빈 문자열을 가지도록 생성하는 방식
string in_str;       
string in_str2;       
string in_str3;       

//생성자에 초기값을 넘겨주는 방식
string inltial_str1 = "yunseong";
string initial_str2 = ("AnYujin");

//c-string 과 호환
char s[] = {'a','r','m','y'};
string cs_str3(s);

//문자열 내용을 복사한 새로운 객체 생성 방식(복사 생성자?)
string copy_str(cs_str3);

//string 객체 배열을 한 문자씩 접근.
string kimminju = "kimminju";
cout<<"kimminju[0]:"<<kimminju[0];

//string 객체 배열을 한 객체씩 접근.
string joyuriz[3];
joyuriz[0] = "JoYuri";
joyuriz[1] = "ChoiYena";
joyuriz[2] = "KimChaeWon";

cout<<"JoYuriz"<<endl;
for(int i=0; i<3; i++)
    cout<<joyuriz[i]<<' ';

cout<<endl;

//new,delete #1 (dynamic allocation)
string *p = new string(); //new를 이용한 동적할당
p->append("iz one");    //append :덧붙이다. 추후 설명
cout<<*p<<endl;         
delete p;               //메모리 반환

//new,delete #2 (dynamic allocation)
string *p1 = new string("hello "); // 초기화 가능한듯!
p1->append("world!");
cout<<*p1<<endl;
delete p1;


/*
//스페이스가 있어도 한줄을 통째로 입력받는다. getline(cin,str,'\n')과 같음.
    cout<<"getline(cin,in_str2):";
    getline(cin,in_str2);

//특정한 문자 '(char)' 앞까지만 입력받는다. "chaewon" -> "chae"
    cout<<"getline(cin,in_str3,'w')(write chaewon!):";
    getline(cin,in_str3,'w');

    
//문자열 입력받기. 단, 스페이스를 만나면 첫번째 문단만 입력받는다.
    cout<<"in_str:";
    cin>>in_str;  

    cout<<"in_str:"<<in_str<<endl;
    cout<<"in_str2:"<<in_str2<<endl;
    cout<<"in_str3:"<<in_str3<<endl;
*/

//비교연산자
//1.== 문자열이 같은지 비교. true(0) false(1) bool 값을 반환
cout<<"relational operator == (true : 0 false : 1)"<<endl;
cout<<"(abcde==abced) = "<<(compare_string == compare_string2)<<endl;

//2. '>' '<' 사전 순서 비교. true(1) false(0) 전체 문자를 비교한 결과가 나옴.
//문자열의 값이 크면 사전순서가 늦다.
cout<<"relational operator >,< (true: 1 false: 0)"<<endl;
cout<<"abcde > ccccc :"<<(compare_string > compare_string3)<<endl;
cout<<"abcde < ccccc :"<<(compare_string < compare_string3)<<endl;

//메소드 
//1.length(), size() 문자열 길이 반환
cout<<"(AnYujin)initial_str2.size():"<<initial_str2.size()<<endl;
cout<<"(AnYujin)initial_str2.length():"<<initial_str2.length()<<endl;
cout<<"(AnYujin)initial_str2.capacity():"<<initial_str2.capacity()<<endl;

//2.append() 문자열 추가. (뒤에 덧붙힘)
string str = "abc";
str.append("de");
str.append("f");
str = str + 'g';
cout<<"str:"<<str<<endl;
cout<<"(\"abc\"+ \"de\" + \"f\" +'g')"<<endl;
cout<<"append(\"abc\"),append(\"de\"),append(\"f\"),+\'g\'"<<endl;

//3.insert() 문자열 삽입.
cout<<"str:"<<str<<endl;
cout<<"str[2] insert \"ab\":"<<str.insert(2,"ab")<<endl;



return 0;
}
