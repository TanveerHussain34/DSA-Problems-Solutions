#include<iostream>
using namespace std;

int n=0;
int N=0;
int val=0;
int ind=0;

bool isFull(int arr[]){
	if(N==n){
		return true;
	}
	else{
		return false;
	}
}

bool isEmpty(int arr[]){
	if(N==0){
		return true;
	}
	else{
		return false;
	}
}

void display(int arr[]){
	cout<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void insertAtZero(int arr[]){
	bool result = isFull(arr);
	if(result){
		cout<<"\nArray is full. You can't add more values!\n";
	}
	else{
		cout<<"\nEnter value to store at zero: ";
		cin>>val;
		for(int i=N; i>0; i--){	
			arr[i]=arr[i-1];
		}
		arr[0]=val;
		N++;
		cout<<"Value stored successfully.\n";
	}
}

void insertAtK(int arr[]){
	bool result = isFull(arr);
	if(result){
		cout<<"\nArray is full. You can't add more values!\n";
	}
	else{
		A:
		cout<<"\nEnter index(0 to "<<n-1<<") to store value: ";
		cin>>ind;
		if(ind>=0 && ind<n){
			cout<<"\nEnter value to be stored: ";
			cin>>val;
			if(arr[ind]==0){
				arr[ind]=val;
				N++;
			}
			else{
				for(int i=N; i>ind; i--){
					arr[i]=arr[i-1];
				}
				arr[ind]=val;
				N++;
			}
		}
		else{
			cout<<"Please enter correct position number!";
			goto A;
		}
	}
}

void insertAtEnd(int arr[]){
	bool result = isFull(arr);
	if(result){
		cout<<"\nArray is full. You can't add more values!\n";
	}
	else{
		cout<<"\nEnter value to store at end: ";
		cin>>val;
		if(arr[n-1]==0){
			arr[n-1]=val;
			N++;
		}
		else{
			for(int i=0; i<n-1; i++){	
				arr[i]=arr[i+1];
			}
			arr[n-1]=val;
			N++;
			cout<<"Value stored successfully.\n";
		}	
	}
}

void deleteAtZero(int arr[]){
	bool result = isEmpty(arr);
	if(result){
		cout<<"\nArray is empty. You can't remove a value!\n";
	}
	else{
		for(int i=0; i<n-1; i++){	
			arr[i]=arr[i+1];
		}
		arr[n-1]=0;
		N--;
		cout<<"\nValue removed successfully.\n";
	}
}

void deleteAtK(int arr[]){
	bool result = isEmpty(arr);
	if(result){
		cout<<"\nArray is empty. You can't remove a value!\n";
	}
	else{
		A:
		cout<<"\nEnter index(0 to "<<n-1<<") to remove value: ";
		cin>>ind;
		if(ind>=0 && ind<n){
			arr[ind]=0;
			for(int i=ind; i<n-1; i++){	
				arr[i]=arr[i+1];
			}
			arr[n-1]=0;
			N--;
			cout<<"\nValue removed successfully.\n";
		}
		else{
			cout<<"Please enter correct position number!";
			goto A;
		}
	}
}

void deleteAtEnd(int arr[]){
	bool result = isEmpty(arr);
	if(result){
		cout<<"\nArray is empty. You can't remove a value!\n";
	}
	else{
		arr[n-1]=0;
		N--;
		cout<<"\nValue removed successfully.\n";
	}	
}

int main(){
	int option;
	bool result;
	cout<<"Enter the maximum size of list: ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		arr[i]=0;
	}
	while(true){
		cout<<"\nEnter 1 to Insert at Zero";
		cout<<"\nEnter 2 to Insert at K";
		cout<<"\nEnter 3 to Insert at End";
		cout<<"\nEnter 4 to Delete at Zero";
		cout<<"\nEnter 5 to Delete at K";
		cout<<"\nEnter 6 to Delete at End";
		cout<<"\nEnter 7 to Display";
		cout<<"\nEnter 0 to Exit";
		cout<<"\nEnter your option: ";
		cin>>option;
		switch(option){
		case 1:
			insertAtZero(arr);
			break;
		case 2:
			insertAtK(arr);
			break;		
		case 3:
			insertAtEnd(arr);
			break;
		case 4:
			deleteAtZero(arr);
			break;
		case 5:
			deleteAtK(arr);
			break;
		case 6:
			deleteAtEnd(arr);
			break;
		case 7:
			display(arr);
			break;
		case 0:	
			exit(0);
		
			break;
		default:
			cout<<"Invalid option selected!";
			break;
		}
	}
	return 0;
}
