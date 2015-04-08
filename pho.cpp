//012-lxw
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;

class Telbook{
	public:
		string name,number;

		Telbook(string st="NULL",string nu="NULL"){
			name=st;
			number=nu;
		}	
		~Telbook(){
			//cout<<"Telbook的析构函数被调用"<<endl;
		}
		void pri(){
			cout<<"name:"<<name<<"   "<<"phonenumber:"<<number<<endl;
		}
};		//定义一个电话本的类 

int main(){
	char ch,cho;
	string str,str0;
	Telbook teph[100];		//定义一个电话本数组 
	int i=0,j=0;
	
	ifstream infile;
	infile.open("pho.txt");		//打开文件 ，用于读取文件数据到内存 
	if(!infile){
		cerr<<"打开pho文件失败！！"<<endl;
		return -1;
	}
	else{
		while(infile>>teph[i].name>>teph[i].number){
			i++;
		}
		cout<<"请输入你的选择：" <<endl;
		cout<<"a.打印电话本"<<endl;
		cout<<"b.进行查找(包括删除操作)"<<endl;
		cout<<"c.添加新的电话号码"<<endl; 
		cout<<"x.退出电话本程序(并保存到文本文件)"<<endl;
		cin>>ch; 
		while(ch!='x'){
			switch(ch){
				case 'a':
					cout<<"-----phone book-----:"<<endl;
					for(i=0;i<100;i++){
						if(teph[i].name!="NULL"&&teph[i].name!="null")
						teph[i].pri();
					}
					cout<<endl<<"打印完毕；"<<endl<<endl;;
					break;
				case 'b':
					cout<<"请输入你想要查找的姓名："<<endl;
					cin>>str;
					for(i=0;i<100;i++){
						if(str==teph[i].name){
							j=i;
							i=101;
						}
					}
					if(i==100)
					cout<<"没有你所输入的联系人。"<<endl;
					if(i=101){
						cout<<"查找成功！"<<endl; 
						cout<<"是否对  姓名："<<teph[j].name<<"   电话号码："<<teph[j].number<<" 进行删除？"<<endl;
						cout<<"y为确认删除，其他任意字符为否："<<endl;
						cin>>cho;
						if(cho=='y'){
							teph[j].name="null";
							teph[j].number="null";
						}
						j=0;
					}
					cout<<endl;
					break;	
				case 'c':
					i=0;
					while(teph[i].name!="NULL"){
						i++;
					}	
					if(i<100){
						cout<<"请输入你想添加的电话号码："<<endl;
						cout<<"name:";
						cin>>teph[i].name;
						cout<<"telephone number:";
						cin>>teph[i].number;
						cout<<"已存入！"<<endl;
					}
					else
						cout<<"电话本已经存满！！"<<endl;
					cout<<endl;	
					break;
				default:
					cout<<"输入有误"<<endl;	
						
			} 
			cout<<"请输入你的选择：" <<endl;
			cout<<"a.打印电话本"<<endl;
			cout<<"b.进行查找(包括删除操作)"<<endl;
			cout<<"c.添加新的电话号码"<<endl; 
			cout<<"x.退出电话本程序(并保存到文本文件)"<<endl;
			cin>>ch;
		}
	} 
	infile.close();
	ofstream outfile("pho.txt");		//打开文件 ，用于写入内存数据到文件 
	if(!outfile){
		cerr<<"打开pho文件失败！！"<<endl;
		return -1;
	}
	else{
		for(int k=0;k<100;k++){
			if(teph[k].name!="NULL"&&teph[k].name!="null"){
				outfile<<teph[k].name<<"    "<<teph[k].number<<endl;
			}
		}
		outfile.close();
		cout<<"文件保存成功！"<<endl; 
		system("pause");
		return 0;
	}
}
