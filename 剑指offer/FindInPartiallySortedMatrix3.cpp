/************************************************************************/
/* 应该还有一个fenye                                                                     */
/************************************************************************/
//二分查找之二维数组二分查找
#include<iostream>
#include <cstdlib>
#include <ctime>
#include<algorithm>
#include <utility>
#include <iomanip>
using namespace std;

pair<int,int> BinarySearchX(int ** arr,int X,pair<int,int> const& pos,int const val)
{
	typedef pair<int,int> pairI;
	int beg =pos.first;
	int end = pos.second;
	while(beg<=end)
	{
		int mid = (beg+end)/2;
		if(val==arr[X][mid])
		{
			return pairI(X,mid);
		}
		if(val<arr[X][mid] )
		{
			end = mid-1;
		}
		else
		{
			beg = mid+1;
		}
	}
	return pairI(-1,-1);
}
pair<int,int> BinarySearchY(int ** arr,int Y,pair<int,int> const& pos,int const val)
{
	typedef pair<int,int> pairI;

	int beg =pos.first;
	int end = pos.second;
	while(beg<=end)
	{
		int mid = (beg+end)/2;
		if(val == arr[mid][Y])
		{
			return pairI(mid,Y);
		}
		if(val<arr[mid][Y])
		{
			end = mid-1;
		}
		else
		{
			beg = mid+1;
		}
	}
	return pairI(-1,-1);
}

pair<int,int> BinarySearch(int ** arr,pair<int,int> beg,pair<int,int> end,int const val)
{
	typedef pair<int,int> pairI;
	if(beg.first>end.first ||beg.second>end.second)
		return pairI(-1,-1);
	if(val<arr[beg.first][beg.second]||val>arr[end.first][end.second])
	{
		return pairI(-1,-1);
	}
	while(beg.first<=end.first&&beg.second<=end.second)
	{
		if(beg.first==end.first)
		{
			return BinarySearchX(arr,beg.first,pairI(beg.second,end.second),val);
		}
		else if(beg.second == end.second)
		{
			return BinarySearchY(arr,beg.second,pairI(beg.first,end.first),val);
		}
		if((end.first-beg.first)==1&&(end.second-beg.second)==1)
		{
			if(arr[beg.first][beg.second] == val)
				return beg;
			if(arr[end.first][end.second] == val)
				return end;
			if(arr[beg.first][beg.second+1] == val)
				return pairI(beg.first,beg.second+1);
			if(arr[beg.first+1][beg.second] == val)
				return pairI(beg.first+1,beg.second);
			return pairI(-1,-1);            
		}
		pairI mid((beg.first+end.first)/2,(beg.second+end.second)/2);
		if(val ==arr[mid.first][mid.second])
			return mid;

		pairI ret = BinarySearch(arr,pairI(beg.first,mid.second+1),pairI(mid.first-1,end.second),val);
		if(ret.first!=-1)
			return ret;
		ret = BinarySearch(arr,pairI(mid.first+1,beg.second),pairI(end.first,mid.second-1),val);
		if(ret.first!=-1)
			return ret;

		if(val <arr[mid.first][mid.second])
		{
			end = mid;
		}
		else
		{
			beg= mid;
		}
	}
	return pairI(-1,-1);    
}


pair<int,int> BinarySearch(int ** arr,pair<int,int>&const size,int const val)
{
	typedef pair<int,int> pairI;
	return BinarySearch(arr,pairI(0,0),pairI(size.first-1,size.second-1),val);

}

int main(int argc, char* argv[])
{
	srand(time(0));
	int const sizeX = 200;
	int const sizeY = 5000;
	typedef pair<int,int> pairI;
	int ** arr = new int *[sizeX];
	for(int i =0;i<sizeX;++i)
		arr[i] = new int[sizeY];
	arr[0][0] = rand()%20;
	for(int i =1;i<sizeY;++i)
	{
		arr[0][i] =arr[0][i-1]+rand()%10;
	}
	for(int i =1;i<sizeX;++i)
	{
		arr[i][0] = arr[i-1][0]+rand()%10;
	}
	for(int i=1;i<sizeX;++i)
	{
		for(int j=1;j<sizeY;++j)
		{
			arr[i][j] = max(arr[i-1][j],arr[i][j-1]) + rand()%10;
		}
	}

	//for(int i=0;i<sizeX;++i)
	//{
	//	for(int j=0;j<sizeY;++j)
	//	{
	//		cout<<setw(5)<<arr[i][j];
	//	}
	//	cout<<endl;
	//}
	/*for(int i=0;i<sizeX;++i)
	{
		for(int j=0;j<sizeY;++j)
		{
			pairI ret = BinarySearch(arr,pairI(sizeX,sizeY),arr[i][j]);

			if(ret.first == -1||arr[ret.first][ret.second]!=arr[i][j])
			{
				cout<<"error"<<endl;
			}
			else
				cout<< "it's pos: "<<"(i,j)"<<ret.first<<","<<ret.second<<endl;

		}        
	}*/
	pairI ret = BinarySearch(arr,pairI(sizeX,sizeY),100);
	if(ret.first == -1||arr[ret.first][ret.second]!=100)
	{
		cout<<"error"<<endl;
	}else
		cout<< "100 pos: "<<"(i,j)"<<ret.first<<","<<ret.second<<endl;
	return 0;
}