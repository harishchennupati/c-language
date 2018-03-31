
#include<iostream>
#include<string>
using namespace std;


void space()
{

int i;
for(i=1;i<=6;i++)
cout<<" ";
}


struct day


{


string name;


struct day *rlink;


struct day *llink;


};


day *t;


struct node


{


int data;


struct node *rlink;


day *llink;


};


day *root1;


node *root;


void append(int data)


{


node *temp,*p;


temp = new node;


temp->data=data;


temp->rlink=NULL;


temp->llink=NULL;


if(root==NULL)


{


root = temp;


}


else if(root->rlink==NULL)


{


root->rlink=temp;


} else


{


p=root;


while(p->rlink!=NULL)


{


p=p->rlink;


}


p->rlink=temp;


}


}


void append()


{


string s;


day *temp,*p;


temp = new day;


cout<<"enter the day name"< cin>>s;


temp->name=s;


temp->rlink=NULL;


if(root1==NULL)


{


root1 = temp;


}


else if(root1->rlink==NULL)


{


root1->rlink=temp;


}


else


{


p=root1;


while(p->rlink!=NULL)


{


p=p->rlink;


}


p->rlink=temp;


}


}


void delete_node()


{


node *p,*t;


p=root;


t=root;


while(p->rlink!=NULL)


{


t=p;


p=p->rlink;


}


t->rlink=NULL;


p=NULL;


}


int main()


{


node *p;


day *s;


int i,no;


for(i=1;i<=31;i++)

{


append(i);


}


for(i=1;i<=7;i++)

{ append();


}


s = root1;


while(s->rlink!=NULL)


{


s=s->rlink;


}


s->rlink=root1;


s=root1;


p=root;


s=s->rlink;


t=s;


for(i=1;i<=31;i++)

{


p->llink=s;


s=s->rlink;


p=p->rlink;


}


cout<<"enter a number "< /* cin>>no;


p=root;


while(p->data!=no)


{


p=p->rlink;


}


s=p->llink;


cout<name;*/


s=root1;


while(s->rlink!=root1)


{


cout<name;


cout<<" ";

s=s->rlink;


} cout<name< p=root;


cout<<"january"< day*q=root1;


while(q!=p->llink)


{


cout<<" ";

space();


q=q->rlink;


}


s=p->llink


; for(i=1;i<=31;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout<< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=28;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=31;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=30;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=31;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=30;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=31;i++) {

if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=31;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();




}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=30;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=31;i++) {

if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=30;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}


cout< q=root1;


while(q!=s)


{


cout<<" ";

space();


q=q->rlink;


}


for(i=1;i<=31;i++)

{


if(i<10)

{


cout< cout<<" ";

space();


}


else


{


cout< cout<<" ";

space();


}


if(s->rlink==root1)


cout< s=s->rlink;


}
}
