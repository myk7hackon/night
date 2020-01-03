#include<iostream>
using namespace std;
class list
{
	public:
	int a;
	list *next;
	
/*	list(int p)
	{
		a=p;
		next=NULL;
	}*/
};
void buildlist(list **start,int p)
{
	list *temp=new list;
	temp->a=p;
	temp->next=NULL;
	if(*start==NULL)
	*start=temp;
	else
	{
	list *copy=*start;
	while(copy->next!=NULL)
	copy=copy->next;
	copy->next=temp;
	
}
}
void atpos(list **start,int p,int val)
{
	list *temp=new list;
	temp->a=val;
	temp->next=NULL;

	if(p==1)
	{
	temp->next=*start;
	*start=temp;
}
else
{
	list *copy=*start;
	int count=0;
	while(copy->next!=NULL&&count<p-2)
	{
		copy=copy->next;
		count++;
	}
	if(count!=p-2)
	cout<<"NOT enough values in the list";
	else
	{
		temp->next=copy->next;
		copy->next=temp;
	}
}
}
void delpos(list **start,int p)
{

	if(p==1)
*start=(*start)->next;
else
{
	list *copy=*start;
	while(copy->next!=NULL&&p-2!=0)
	{
		copy=copy->next;
		p--;
	}
	if(p-2>0)
	cout<<"NOT enough values in the list";
	else
		copy->next=copy->next->next;
}
}
int cyclefinder(list *start)
{
	list *slow=start;
	list *fast=start;
	if(slow->next==NULL)
	return 0;
	else
	slow=slow->next;
	if(fast->next==NULL || fast->next->next==NULL)
	return 0;
	else
	fast=fast->next->next;
	while(1)
	{
	if(fast==slow)
		{
			cout<<fast->a<<endl;
			break;
		}
		if(slow->next==NULL)
		break;
		else
		slow=slow->next;
		if(fast->next==NULL || fast->next->next==NULL)
		break;
		else
		fast=fast->next->next;
	}
	slow=fast;
	fast=fast->next;
	int ans=0;
	while(fast!=slow)
	{fast=fast->next;
	ans++;
}
	cout<<ans<<endl;
	return 0;
}
list *traverse;
void reverse(list **start,int val,list *prev)
{
	list *curr,*next;
	curr=*start;
	//prev=NULL;
	int temp=0;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		temp++;
	}
	
//	cout<<prev->next->a;
}
list* riverse(list *start,int val,int doi)
{
		list *curr,*next=NULL,*prev=NULL;
	curr=start;
	if(doi==1)
	{
	int temp=0;
	while(temp<val&&curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		temp++;
	}
	if(next!=NULL)
		start->next=riverse(next,val,0);
}
else
	return start;
	return prev;
}
void recrev(list *cur,list *prev,list **start,int val)
{
	if(!cur->next)
	{
		*start=cur;
		return ;
	}
	else if(val==0)
	{
		*start=prev;
		//list **temp=&cur;
		recrev(cur,prev,&cur,val);
	}
	else
{
	list *next=cur->next;
	cur->next=prev;
	recrev(next,cur,start,val-1);
}
}
/*void reverseup(list **start)
{
list **inter=reverse(start,3,NULL);
list *temp=*inter;
while(*inter!=NULL)
inter=reverse((*inter)->next,3,temp);
}*/
/*void revblock(list **start,int win)
{
	link *temp=*start;
	int view=0;
	while(temp!=NULL&&view<win)
	{
		temp=temp->next;
		view++;
	}
	reverseup(start,temp);
}*/
void merge(list* start1,list*start2,list **start3)
{
	if(*start3==NULL)
	{
		*start3=new list;
		if(start1!=NULL&&start2!=NULL)
		{
		(*start3)->a=(start1->a>start2->a)?start2->a:start1->a;
		(*start3)->next=NULL;
		if(start1->a>start2->a)
		merge(start1,start2->next,&((*start3)->next));
		else
		merge(start1->next,start2,&((*start3)->next));
	}
		else if(start1==NULL&&start2!=NULL)
		{
			(*start3)->a=start2->a;
			(*start3)->next=NULL;
			merge(start1,start2->next,&((*start3)->next));	
				}
		
		else if(start2==NULL&&start1!=NULL)
		{
				(*start3)->a=start1->a;
			(*start3)->next=NULL;
			merge(start1->next,start2,&((*start3)->next));	
		}
	
		else 
		return;
}
}
void helper(list *start1,list *start2,list **start3)
{
	if(start1==NULL&&start2==NULL)
	return;
	else if(start1==NULL&&start2!=NULL)
	{
		buildlist(start3,start2->a);
		helper(start1,start2->next,start3);
	}
	else if(start1!=NULL&&start2==NULL)
	{
		buildlist(start3,start1->a);
		helper(start2,start1->next,start3);
	}
	else
	{
		if(start1->a<=start2->a)
		{
			buildlist(start3,start1->a);
		helper(start2,start1->next,start3);
		}
		
		
		else
		{
			buildlist(start3,start2->a);
		helper(start1,start2->next,start3);
		}
	}
}
/*void caller(list **start,int val,list *prev,int size)
{
	if(size>0)
{
	*start=riverse(start,val,prev);
	size-=val;
	list *temp=*start;
	while(temp->next!=prev)
	temp=temp->next;
	caller(start,val,temp,size-val);
}
}*/
void hogya(list **start)
{
	if(*start==NULL)
	return;
	else if((*start)->next->a<(*start)->a)
	{
	(*start)=(*start)->next;
	hogya(start);
}
else
{
	list* temp=*start;
  while(temp!=NULL)
  {
  	if(temp->next)
  	{
	if(temp->next->next)
	{
	if(temp->next->a>temp->next->next->a)
	temp->next=temp->next->next;
	else
	temp=temp->next;
  }
  else
  temp=temp->next;
}
else
  temp=temp->next;
}
}
}
int main()
{
	list *start=new list;
	list *start2=new list;
	start2->a=-7;
	start2->next=NULL;
	start->a=1;
	start->next=NULL;
	int i=2;
	list* firstcopy=start;
	//cout<<(*firstcopy)->a<<endl;
	//list *temp;
	int ar[]={2,14,6,7,5,6,-3,10,11,0};
	while(i<=10)
	{
		/*list* temp=new list;
		temp->a=i;
		temp->next=NULL;
		firstcopy->next=temp;
		firstcopy=firstcopy->next;
		i++;*/
		buildlist(&start,i);
		i++;
	
	}
		list *temp=start;
	while(temp!=NULL)
	{
		cout<<temp->a<<"--->";
		temp=temp->next;
	}
	cout<<endl;
	start=riverse(start,3,1);
	//list **tempi=&(start->next->next->next->next->next->next);
	//temp=riverse(*tempi,3,1);
//	cout<<start->a;
start->next->next->next->next->next->next=riverse(start->next->next->next->next->next->next,3,1);
temp=start;
	while(temp!=NULL)
	{
		cout<<temp->a<<"--->";
		temp=temp->next;
	}
	cout<<endl;
	hogya(&start);
	temp=start;
	while(temp!=NULL)
	{
		cout<<temp->a<<"--->";
		temp=temp->next;
	}
	/*i=-3;
	while(i<=20)
	{
		buildlist(&start2,i);
		i=i+3;
	}
	list *temp=start2;
	while(temp!=NULL)
	{
		cout<<temp->a<<"--->";
		temp=temp->next;
	}
	cout<<endl;
	temp=start;
	while(temp!=NULL)
	{
		cout<<temp->a<<"--->";
		temp=temp->next;
	}
	cout<<endl;
	list *start3=NULL;
	helper(start,start2,&start3);
	temp=start3;
	while(temp!=NULL)
	{
		cout<<temp->a<<"--->";
		temp=temp->next;
	}
	cout<<endl;
	recrev(start3,NULL,&start3,3);
	temp=start3;
	while(temp!=NULL)
	{
		cout<<temp->a<<"--->";
		temp=temp->next;
	}
	cout<<endl;
	//cout<<endl<<start->next->a;
	/*atpos(&start,3,88);
	list *temp=start;
	while(start!=NULL)
	{
		cout<<start->a<<"--->";
		start=start->next;
	}
	cout<<endl;
	delpos(&temp,1);
	while(temp!=NULL)
	{
		cout<<temp->a<<"--->";
		temp=temp->next;
	}*/
	/*start->next->next->next->next->next->next->next=start;
	cyclefinder(start);
	*/
//	list *prev,*next;
//	prev=NULL;
//	next=NULL;
	
	//cout<<start->a;
	/*recrev(start,NULL,&start,3);
	
	while(start!=NULL)
	{
		cout<<start->a<<"--->";
		start=start->next;
	}*/
	return 0;
}
