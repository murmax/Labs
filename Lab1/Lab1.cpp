#define WIDTH 80
#include <iostream>

int main()
{
    int n, k;
    std::cout<<"Enter amount of pages: "<<std::endl; std::cin>>n;


    do{
    std::cout<<std::endl;
    std::cout<<"Enter which page is opened now: "<<std::endl; std::cin>>k;

    if (k>3)     std::cout<<"1 ";
    if (k>4)     std::cout<<".. ";
    if (k>2)     std::cout<<k-2<<" ";
    if (k>1)     std::cout<<k-1<<" ";
    std::cout<<"["<<k<<"] ";
    if (k<n)     std::cout<<k+1<<" ";
    if (k<n-1)   std::cout<<k+2<<" ";
    if (k<n-3)   std::cout<<".. ";
    if (k<n-2)   std::cout<<n;
    } while((k>0)&&(k<=n));
    std::cout<<std::endl<<"Over";

    return 0;
}
