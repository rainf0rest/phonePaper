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
			//cout<<"Telbook����������������"<<endl;
		}
		void pri(){
			cout<<"name:"<<name<<"   "<<"phonenumber:"<<number<<endl;
		}
};		//����һ���绰������ 

int main(){
	char ch,cho;
	string str,str0;
	Telbook teph[100];		//����һ���绰������ 
	int i=0,j=0;
	
	ifstream infile;
	infile.open("pho.txt");		//���ļ� �����ڶ�ȡ�ļ����ݵ��ڴ� 
	if(!infile){
		cerr<<"��pho�ļ�ʧ�ܣ���"<<endl;
		return -1;
	}
	else{
		while(infile>>teph[i].name>>teph[i].number){
			i++;
		}
		cout<<"���������ѡ��" <<endl;
		cout<<"a.��ӡ�绰��"<<endl;
		cout<<"b.���в���(����ɾ������)"<<endl;
		cout<<"c.����µĵ绰����"<<endl; 
		cout<<"x.�˳��绰������(�����浽�ı��ļ�)"<<endl;
		cin>>ch; 
		while(ch!='x'){
			switch(ch){
				case 'a':
					cout<<"-----phone book-----:"<<endl;
					for(i=0;i<100;i++){
						if(teph[i].name!="NULL"&&teph[i].name!="null")
						teph[i].pri();
					}
					cout<<endl<<"��ӡ��ϣ�"<<endl<<endl;;
					break;
				case 'b':
					cout<<"����������Ҫ���ҵ�������"<<endl;
					cin>>str;
					for(i=0;i<100;i++){
						if(str==teph[i].name){
							j=i;
							i=101;
						}
					}
					if(i==100)
					cout<<"û�������������ϵ�ˡ�"<<endl;
					if(i=101){
						cout<<"���ҳɹ���"<<endl; 
						cout<<"�Ƿ��  ������"<<teph[j].name<<"   �绰���룺"<<teph[j].number<<" ����ɾ����"<<endl;
						cout<<"yΪȷ��ɾ�������������ַ�Ϊ��"<<endl;
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
						cout<<"������������ӵĵ绰���룺"<<endl;
						cout<<"name:";
						cin>>teph[i].name;
						cout<<"telephone number:";
						cin>>teph[i].number;
						cout<<"�Ѵ��룡"<<endl;
					}
					else
						cout<<"�绰���Ѿ���������"<<endl;
					cout<<endl;	
					break;
				default:
					cout<<"��������"<<endl;	
						
			} 
			cout<<"���������ѡ��" <<endl;
			cout<<"a.��ӡ�绰��"<<endl;
			cout<<"b.���в���(����ɾ������)"<<endl;
			cout<<"c.����µĵ绰����"<<endl; 
			cout<<"x.�˳��绰������(�����浽�ı��ļ�)"<<endl;
			cin>>ch;
		}
	} 
	infile.close();
	ofstream outfile("pho.txt");		//���ļ� ������д���ڴ����ݵ��ļ� 
	if(!outfile){
		cerr<<"��pho�ļ�ʧ�ܣ���"<<endl;
		return -1;
	}
	else{
		for(int k=0;k<100;k++){
			if(teph[k].name!="NULL"&&teph[k].name!="null"){
				outfile<<teph[k].name<<"    "<<teph[k].number<<endl;
			}
		}
		outfile.close();
		cout<<"�ļ�����ɹ���"<<endl; 
		system("pause");
		return 0;
	}
}
