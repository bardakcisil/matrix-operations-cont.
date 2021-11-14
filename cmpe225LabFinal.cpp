#include<iostream>
#include <cstdlib>  // for Random

const int  minValue=0;
const int maxValue=25;
	
using namespace std;
template <class A>  //class template
class Matrix{
	private:
	A **arry;

	public:
	int row;
	int col; 
	bool isMissionComplete; // destructor-controller. After each iostream use and overload, the destructor is automatically run
			
		// constructor 
		Matrix(int r=4, int c=4) {
			row = r;
			col = c;
			arry=new  A*[row];
			for(int i=0;i<row;i++)
				arry[i]=new A [col];	
				
            cout<< "[" << row << "][" << col << "] Matrix object has been created\n" << endl;
            
			isMissionComplete = false; 
		 }


		//destructor
		~Matrix() {
			if (isMissionComplete) {
 				for(int i=0; i< row; i++) 
           	 	{	 
		    		delete arry[i]; // Delete arry object
					cout<< "Matrix object has been destroyed.\n" << endl;
				}
				delete arry; // Delete arry
				cout<< "Matrix has been destroyed.\n" << endl;
			}
		}		
		
			
		// operator >> is overloaded input
		friend istream& operator>>(istream& is, Matrix<A>& obj){ 
		
		cout<<"!!! WARNING !!! The values must be enterred one by one. Please dont use the space bar! "<<endl<<endl;
			for(int i=0; i<obj.row; i++) 
            { 
                for(int j=0; j<obj.col; j++) 
                { 
                	cout<< "Please enter the matrix element (" << minValue << "-" << maxValue << ")    [" << i << "][" << j << "] : ";
                	
					is>>obj.arry[i][j];
				
					if ( (obj.arry[i][j] < minValue ) || (obj.arry[i][j] > maxValue ) ){

						// a value randomly between 0-25
						obj.arry[i][j] = rand() % maxValue ;
						
						cout<< " -> Out of (" << minValue << "-" << maxValue << ")  Random " << obj.arry[i][j] << " entered.\n";	
					}
				}
			} 
			cout<<endl;
		}
	

		// operator << is overloaded output, 	
		friend ostream& operator<<(ostream& os, Matrix<A> obj){
			for(int i=0; i<obj.row; i++) 
            { 
                for(int j=0; j<obj.col; j++) 
                { 
                    if(j==0) os<<"|\t";
                    os<< obj.arry[i][j] <<"\t" ; 
                } 
                os<<"|"<<endl; 
            } 
			return os;
		}

		
		// Operation + 
		Matrix  operator +(const Matrix &obj)
		{ 
			Matrix returnedMatrix(row, col);
			
			for(int i=0; i< row; i++) 
            { 
                for(int j=0; j<col; j++) 
                { 	
					returnedMatrix.arry[i][j] = arry[i][j] + obj.arry[i][j];
				}
            }
			return returnedMatrix;
		}

		
		// Operation - 
		Matrix  operator -(const Matrix &obj)
		{ 
			Matrix returnedMatrix(row, col);
			
			for(int i=0; i< row; i++) 
            { 
                for(int j=0; j<col; j++) 
                { 	
					returnedMatrix.arry[i][j] = arry[i][j] - obj.arry[i][j];
				}
            }
			return returnedMatrix;
		}
		
		
		//  is Quattro Matrix ?	
		isQuattro()
		{
			bool isQ=true;
			if(arry[0][0]!=arry[0][1]+arry[1][0]+arry[1][1]) isQ = false;
			if(arry[0][3]!=arry[0][2]+arry[1][2]+arry[1][3]) isQ = false;
			if(arry[3][0]!=arry[2][0]+arry[2][1]+arry[3][1]) isQ = false;
			if(arry[3][3]!=arry[2][2]+arry[2][3]+arry[3][2]) isQ = false;
			
		    if (isQ) cout<<"This matrix is Quattro Matrix\n"<<endl;
				else cout<<"This matrix Not Quattro Matrix\n"<<endl;	
				
			system("pause");
			
			cout<<"\n"<<endl;	

		}
 
};


main()
{
	// Array create with double type // integer number can use with double type 
	// input Matris objects
	cout<<"1st Matrix (Matrix-A)"<<endl;
	cout<<"--------------------------------------------"<<endl;
	Matrix <double> myArry_A (4,4);	
	cin>>myArry_A;
	cout<<myArry_A<<endl<<endl;
	
	//  is Quattro Matrix ?	
	myArry_A.isQuattro();

	cout<<"2nd Matrix (Matrix-B)"<<endl;
	cout<<"--------------------------------------------"<<endl;
	Matrix <double> myArry_B (4,4);	
	cin>>myArry_B;
	cout<<myArry_B <<endl<<endl;

	//  is Quattro Matrix ?	
	myArry_B.isQuattro();

	// Operation + -
	string chr="";
	while (true)
	{
		cout<<"For (Matrix A + Matrix B) Press +"<<endl;
		cout<<"For (Matrix A - Matrix B) Press -"<<endl;
		cout<<"Please Enter your choice : ";

    	cin >> chr;
    	
    	if ((chr== "+") || (chr == "-")) break	;
 	 }  

	cout<<"\n"<<endl;	

	// Operation (Matrix A + Matrix B)
	if (chr== "+")
	{
		cout<<"Operation (Matrix A + Matrix B)"<<endl;
		cout<<"--------------------------------------------"<<endl;	
	
		// Create new Matrix with Operation (Matrix A + Matrix B)
		Matrix <double> myArry_C (myArry_A + myArry_B);
	
		cout<<"Matrix - A"<<endl;	
		cout<<myArry_A <<endl<<endl;
		cout<<"Matrix - B"<<endl;	
		cout<<myArry_B <<endl;	
		cout<<"--------------------------------------------"<<endl;	
		cout<<"Matrix A + Matrix B"<<endl;	
		cout<<myArry_C <<endl<<endl;
		
		//  is Quattro Matrix ?	
		myArry_C.isQuattro();

	}
	else  // Operation (Matrix A - Matrix B)
	{
		cout<<"Operation (Matrix A - Matrix B)"<<endl;
		cout<<"--------------------------------------------"<<endl;	

		// Create new Matrix with Operation (Matrix A - Matrix B)
		Matrix <double> myArry_C (myArry_A - myArry_B);

		cout<<"Matrix - A"<<endl;	
		cout<<myArry_A <<endl<<endl;
		cout<<"Matrix - B"<<endl;
		cout<<myArry_B <<endl;	
		cout<<"--------------------------------------------"<<endl;	
		cout<<"Matrix A - Matrix B"<<endl;	
		cout<<myArry_C <<endl<<endl;
		
		//  is Quattro Matrix ?	
		myArry_C.isQuattro();	
	}
	
	
	myArry_A.isMissionComplete = true;
	myArry_A.~Matrix();
	myArry_B.isMissionComplete = true;
	myArry_B.~Matrix();

	
}
