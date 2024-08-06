//
//  main.cpp
//  YaAllahplshelp
//
//  Created by Syeda Laraib Fatima on 29/09/2022.
//

#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>

using namespace std;
using namespace cv;


// -------------------------------------structure and class for Question two
struct n{
    int x;
    struct n * next;
};

class l{
    n* head;
public:
    l();
    int insert(int a);
};

l::l(){
    head=NULL;
}
int l::insert(int a){
    if (head==NULL){
        n * temp1= new n;
        n * temp= new n;
        head=temp1;
        temp1->x=0;
        temp1->next=temp;
        temp->x=a;
        temp->next= NULL;
        return 0;
        
    }
    else {
        n * temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        n * p = new n;
        p->x=a;
        temp->next=p;
        p->next= NULL;
        if (p->x!=temp->x)
            return 0;
        else
            return 1; // return 1 if equal
    }

}

//----------------------------------Structure and class for question Four
struct node{
    int sp; // string point
    int ep; // ending point
    struct node * next;
};

class list{
    node * head;
public:
    list();
    void insert(int a, int b);
    void print();
};

list::list()
{
    head= NULL;
    
}

void list::insert(int a, int b ){
    if (head==NULL){
        node * temp= new node;
        head= temp;
        temp->sp=a;
        temp->sp=b;
        temp->next= NULL;
    }
    else
    {
        node * temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        node * p = new node;
        p->sp=a;
        p->ep=b;
        temp->next=p;
        p->next= NULL;
    }
}

void list::print()
{
    node * ptr=head;
    while (ptr->next!= NULL)
    {
        if (ptr->sp==-1)
        {
            cout<< ptr->sp<<endl;
        }
        else {
            cout<<ptr->sp<<" "<<ptr->ep<<"  ";
        }
        ptr=ptr->next;
        
    }
}

//-------------------------------------------------Main
int main(int argc, const char * argv[]) {
   
    // images used in Question One and Question 4
    // image reading
    Mat image = imread("/Users/syedalaraibfatima/Documents/Segmented Outputs/6.bmp", IMREAD_GRAYSCALE);
        // Error Handling
        if (image.empty()) {
            cout << "Image File "
                 << "Not Found" << endl;
      
            // wait for any key press
            cin.get();
            return -1;
        }
    
    
    // nested loops to convert the picture into pixels that are saved in the 2d array named array
      int ** array = new int *[image.rows];
        for(int i=0;i<image.rows;i++)
        {
            *(array+i)= new int [image.cols];
        for (int j=0;j<image.cols;j++)
          {
             *(*(array+i)+j)=int(image.at<uchar>(i,j));
          }
        }
    
    
    int ch;
    cout<< "Which question do youu want to open?"<<endl;
    cin>> ch;
    if (ch==1){   //------------------------------------Question 1
         int a=1;
        int small, large;
                for (int i = 0; i < image.rows; i++)
                {
                    for (int j = 0; j < image.cols; j++)
                    {
                        if (i==0) // do nothing at the first row
                        {}
                        else {
                            if (j==0 || j==(image.cols-1)) //do nothing at first column and last colum
                            {}
                            else {
                                if (array[i][j]==255)
                                {
                                    if ( array[i][j-1]!=0 ) // the pixel to the left of the pixel is checked
                                    {
                                        if (array[i-1][j-1]!=0 && array[i][j-1]!=array[i-1][j-1]) // if upper left pixel and left pixel are same
                                        {
                                            if (array[i][j-1]<array[i-1][j-1])
                                            {
                                                array[i][j]=array[i][j-1];
                                                small=array[i][j-1];
                                                large=array[i-1][j-1];
                                            }
                                            else
                                            {
                                                array[i][j]=array[i-1][j-1];
                                                small=array[i-1][j-1];
                                                large=array[i][j-1];
                                            }
                                            
                                            for (int k=0 ; k<i;k++){
                                                for (int l=0; l<image.cols;l++){
                                                    if (array [k][l]==large)
                                                    {
                                                        array[k][l]=small;
                                                    }
                                                }
                                            }
                                        }
                                        else if (array[i-1][j]!=0 && array[i][j-1]!=array[i-1][j])
                                        {
                                            if (array[i][j-1]<array[i-1][j])
                                            {
                                                array[i][j]=array[i][j-1];
                                                small=array[i][j-1];
                                                large=array[i-1][j];
                                            }
                                            else
                                            {
                                                array[i][j]=array[i-1][j];
                                                small=array[i-1][j];
                                                large=array[i][j-1];
                                            }
                                    
                                            
                                            for (int k=0 ; k<i;k++){
                                                for (int l=0; l<image.cols;l++){
                                                    if (array [k][l]==large)
                                                        array[k][l]=small;
                                                }
                                            }
                                        }
                                        else if (array[i-1][j+1]!=0 && array[i][j-1]!=array[i-1][j+1])
                                        {
                                            if (array[i][j-1]<array[i-1][j+1])
                                            {
                                                array[i][j]=array[i][j-1];
                                                small=array[i][j-1];
                                                large=array[i-1][j+1];
                                            }
                                            else
                                            {
                                                array[i][j]=array[i-1][j+1];
                                                small=array[i-1][j+1];
                                                large=array[i][j-1];
                                            }
                                            for (int k=0 ; k<i;k++){
                                                for (int l=0; l<image.cols;l++){
                                                    if (array [k][l]==large)
                                                        array[k][l]=small;
                                                }
                                            }
                                        }
                                    
                                        else
                                        {
                                            array[i][j]=array[i][j-1];
                                        }
                        
                                    }
                                    else if (array[i-1][j]!=0 ) // the pixel, above to the pixel is checked
                                    {
                                        if (array[i-1][j+1]!=0 && array[i-1][j]!=array[i-1][j+1])
                                            {
                                                if (array[i-1][j]<array[i-1][j+1])
                                                {
                                                    array[i][j]=array[i-1][j];
                                                    small=array[i-1][j];
                                                    large=array[i-1][j+1];
                                                }
                                                else
                                                {
                                                    array[i][j]=array[i-1][j+1];
                                                    small=array[i-1][j+1];
                                                    large=array[i-1][j];
                                                }
                                                for (int k=0 ; k<i;k++){
                                                    for (int l=0; l<image.cols;l++){
                                                        if (array [k][l]==large)
                                                            array[k][l]=small;
                                                    }
                                                }
                                            }
                                       else if (array[i-1][j-1]!=0 && array[i-1][j]!=array[i-1][j-1])
                                        {
                                            if (array[i-1][j]<array[i-1][j-1])
                                            {
                                                array[i][j]=array[i-1][j];
                                                small=array[i-1][j];
                                                large=array[i-1][j-1];
                                            }
                                                
                                            else
                                            {
                                                array[i][j]=array[i-1][j-1];
                                                small=array[i-1][j-1];
                                                large=array[i-1][j];
                                                
                                            }
                                            for (int k=0 ; k<i;k++){
                                                for (int l=0; l<image.cols;l++){
                                                    if (array [k][l]==large)
                                                        array[k][l]=small;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            array[i][j]=array[i-1][j];
                                        }
                                    }
                                        
                                    else if (array[i-1][j-1]!=0 )// the pixel to the up left diagnol of the pixel is checked
                                    {
                                        if (array[i-1][j+1]!=0 && array[i-1][j+1]!=array[i-1][j-1])
                                        {
                                            if (array[i-1][j-1]<array[i-1][j+1])
                                            {
                                                array[i][j]=array[i-1][j-1];
                                                small=array[i-1][j-1];
                                                large=array[i-1][j+1];
                                                
                                            }
                                            else
                                            {
                                                array[i][j]=array[i-1][j+1];
                                                small=array[i-1][j+1];
                                                large=array[i-1][j-1];
                                            }
                                            for (int k=0 ; k<i;k++){
                                                for (int l=0; l<image.cols;l++){
                                                    if (array [k][l]==large)
                                                        array[k][l]=small;
                                                }
                                            }
                                        }
                                        else
                                            array[i][j]=array[i-1][j-1];
                                    }
                                        
                                    else
                                        array[i][j]=a++;
                                }
                            }
                        }
                    }
                }
                
                int arr[a];
                for (int i=0 ; i<a;i++)
                {
                    arr[i]=1;
                }
                for (int i = 0; i < image.rows; i++) {
                    for (int j = 0; j < image.cols; j++){
                        arr[array[i][j]]+=1;
                    }
                }
            //
                int larg = -1;
                int index=0;
                for(int i=1; i<a-1; i++)
                {
                    if(larg<arr[i]){   // finding the greatest number of pixel's label
                        larg = arr[i];
                        index=i;
                    }
                }
        
        
                for (int i = 0; i < image.rows; i++) {
                    for (int j = 0; j < image.cols; j++){
                        if (array[i][j]==index)   // converting the greatest number of label to 1 and rest to 0
                            array[i][j]=255;
                        else
                            array[i][j]=0;
                        }
                    }
        
        imshow(" Q1: segmented picture", image);

           for(int i=0;i<image.rows;i++)
           {
           for (int j=0;j<image.cols;j++)
             {
                (image.at<uchar>(i,j))=*(*(array+i)+j);
             }
           }

        imshow("Q1: laraib's picture ", image);

        
        
        int ch;
        cout<<"Do you want to see question 3?"<<endl;
        cin>>ch;
        if (ch==1)    // -------------------------------------Question Three----> q1
        {
            Mat ima = imread("/Users/syedalaraibfatima/Documents/Ground Truths/6.bmp", IMREAD_GRAYSCALE);
            int ** arra = new int *[ima.rows];
               for(int i=0;i<ima.rows;i++)
               {
                   *(arra+i)= new int [ima.cols];
               for (int j=0;j<ima.cols;j++)
                 {
                    *(*(arra+i)+j)=int(ima.at<uchar>(i,j));
                 }
               }
            imshow("ground truth", ima);
            float tp=0, fp=0, fn=0, dc;
            for (int i=0; i<ima.rows;i++){
                for (int j=0; j<ima.cols;j++){
                    if (arra[i][j]==array[i][j] && array[i][j]==255)
                        tp++;
                    else if (arra[i][j]!=array[i][j] && array[i][j]==0)
                    {
                        fn++;
                    }
                    else if(arra[i][j]!=array[i][j] && array[i][j]==255)
                    {
                        fp++;
                    }
                }
            }
            
            dc= (2*tp)/(fn+(2*tp)+fp) ;
            cout<<"----------------------------------"<<endl;;
            cout<<"tp:"<<tp<<endl;
            cout<<"fn:"<<fn<<endl;
            cout<<"fp:"<<fp<<endl;
            cout<<"dice coefficient:"<<dc;
        
    }
    }
    else if (ch==2)  //------------------------------------------Question 2
    {
        int c1=31, c2=180; // c1 and c2 are randomly generated clusters
        int sum_c1=0, sum_c2=0, a1, a2, count1=0, count2=0;
        l h1; // object to store mean of c1
        l h2; // object to store mean of c2
        int z=0;
        int y=0;
        Mat im = imread("/Users/syedalaraibfatima/Documents/Original Images/6.bmp", IMREAD_GRAYSCALE);
        int ** arr = new int *[im.rows];
           for(int i=0;i<im.rows;i++)
           {
               *(arr+i)= new int [im.cols];
           for (int j=0;j<im.cols;j++)
             {
                *(*(arr+i)+j)=int(im.at<uchar>(i,j));
             }
           }

        int ** array1 = new int *[im.rows];
           for(int i=0;i<im.rows;i++)
           {
               *(array1+i)= new int [im.cols];
           for (int j=0;j<im.cols;j++)
             {
                *(*(array1+i)+j)=-1;
             }
           }
        
        
        do{
            for (int i = 0; i < im.rows; i++){
                for (int j = 0; j < im.cols; j++){
                    a1=c1-arr[i][j];
                    if (a1<0)
                        a1=arr[i][j]-c1;  // distance between c1 and the point
                    a2=c2-arr[i][j];
                    if (a2<0)
                        a2=arr[i][j]-c2;  // distance between c2 and the point
                    if (a1<a2)            //storing the shortest distance,
                    {
                        sum_c1+=arr[i][j];
                        array1[i][j]=255;
                        count1++;
                        //cout<<"1";
                    }
                    else
                    {
                        sum_c2+=arr[i][j];
                        array1[i][j]=0;
                        count2++;
                        //cout<<"2";
                    }
                }
            }
            c1=sum_c1/count1;
            c2=sum_c2/count2;
            z=h1.insert(c1);
            y=h2.insert(c2);
            
        }while(z==0 && y==0);
        
       // imshow("original picture ", im);
        
           for(int i=0;i<im.rows;i++)
           {
           for (int j=0;j<im.cols;j++)
             {
                (im.at<uchar>(i,j))=*(*(array1+i)+j);
             }
           }
        
        imshow("Q2: laraibs picture ", im);
        
//        Mat x(im.rows, im.cols, CV_32F);
//             for (int i = 0;i < im.rows; ++i)
//                 for (int j = 0; j < im.cols; ++j) {
//                     x.at<float>(i, j) = array[i][j];
//                 }
//                    imshow("haye", x);
        
        int ch;
        cout<<"Do you want to see question 3?"<<endl;
        cin>>ch;
        if (ch==1) // -------------------------------------Question Three----> q2
        {
            Mat ima = imread("/Users/syedalaraibfatima/Documents/Ground Truths/6.bmp", IMREAD_GRAYSCALE);
            int ** arra = new int *[ima.rows];
               for(int i=0;i<ima.rows;i++)
               {
                   *(arra+i)= new int [ima.cols];
               for (int j=0;j<ima.cols;j++)
                 {
                    *(*(arra+i)+j)=int(ima.at<uchar>(i,j));
                 }
               }
            imshow("ground picture", ima);
            float tp=0, fp=0, fn=1, dc;
            for (int i=0; i<ima.rows;i++){
                for (int j=0; j<ima.cols;j++){
                    if (arra[i][j]==array1[i][j] && arra[i][j]==255)
                        tp++;
                    else if (arra[i][j]!=array1[i][j] && array1[i][j]==0)
                    {
                        fn++;
                    }
                    else if(arra[i][j]!=array1[i][j] && array1[i][j]==255)
                    {
                        fp++;
                    }
                }
            }
            
            dc= (2*tp)/(fn+(2*tp)+fp) ;
            cout<<"----------------------------------"<<endl;;
            cout<<"tp:"<<tp<<endl;
            cout<<"fn:"<<fn<<endl;
            cout<<"fp:"<<fp<<endl;
            cout<<"dice coefficient:"<<dc;
            
        }
        else if (ch==0)
        {
            cout<<"OK! BYE"<<endl;
        }
        else
        {
            cout<<"Wrong choice entered"<<endl;
        }
        
        
    }
    else if (ch==4)
    {
        imshow("Q4: segmented images ", image);
        list picture;
        picture.insert(image.rows, image.cols);
        for (int i = 0; i < image.rows; i++) {
            int start=0, end=0;
            bool flag=false;
            for (int j = 0; j < image.cols; j++){
                if (array[i][j]!=0 && j==image.cols-1)
                {
                    picture.insert(j+1,j+1);
                }
                if (array[i][j]!=0 && flag ==false)
                {
                    start =j+1;
                    flag = true;
                }
                if (flag == true && array[i][j]==0)
                {
                    end= j;
                    picture.insert(start, end);
                    flag = false;
                }
            }
            picture.insert(-1,0);
        }
        picture.print();
    }
    
    else {
        cout<<"Wrong option entered"<<endl;
        
    }
  


    ofstream fh;
    fh.open("hi.txt");
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++){
            fh<<array[i][j]<<" ";
            }
        fh<<endl;
        }
//
    
//    for (int i = 0; i < image.rows; i++) {
//        for (int j = 0; j < image.cols; j++)
//            cout << array[i][j]<<" ";
//        cout << endl;
//    }
//

 
    
   // cout << image;
    
    
        // Wait for any keystroke
        waitKey(0);
    
    
    return 0;
}
