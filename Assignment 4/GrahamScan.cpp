#include <bits/stdc++.h>

using namespace std;
 
struct point
{
    int x, y;
};

point pstart;

stack <point> s;

int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool comp(point& p1,point& p2)
{
  int o = orientation(pstart, p1, p2);
  if (o==0)
  {
    int d1 = (pstart.x - p1.x)*(pstart.x - p1.x) + (pstart.y - p1.y)*(pstart.y - p1.y);
    int d2 = (pstart.x - p2.x)*(pstart.x - p2.x) + (pstart.y - p2.y)*(pstart.y - p2.y);
    return (d1<d2);
  }
  return (o == 1);
}

point Prev()
{
    point p = s.top();
    s.pop();
    point res = s.top();
    s.push(p);
    return res;
 }
 
void ConvexHull(int n,point pts[])
{
  int ymin = 0;
  for (int i = 1; i < n; i++)
  {
     if ((pts[i].y < pts[ymin].y) || (pts[i].y == pts[ymin].y && pts[i].x < pts[ymin].x))
        ymin = i;
  }
  //swap
  point temp = pts[0];
  pts[0] = pts[ymin];
  pts[ymin] = temp;

  pstart = pts[0];

  sort(pts+1,pts+n,comp);

  int m = 1; //new size

  for (int i=1; i<n; i++)
  {
      while (i < n-1 && orientation(pstart, pts[i],pts[i+1]) == 0)
        i++;
      pts[m] = pts[i];
      m++;  
  }
   if (m < 3) return;
 
   s.push(pts[0]);
   s.push(pts[1]);
   s.push(pts[2]);

 
   for (int i = 3; i < m; i++)
   {
      while (orientation(Prev(), s.top(), pts[i]) != 2)
        s.pop();
      s.push(pts[i]);
   }

}

int main()
{
  int n;
  cin>>n;
  point *pts = new point[n];
  for(int i = 0; i<n; i++)
  {
    cin>>pts[i].x>>pts[i].y;
  }
  
  clock_t tStart = clock();

  ConvexHull(n,pts);

  double tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;
  int h =0;
  while (!s.empty())
  {
       point p = s.top();
       cout <<p.x << " " << p.y<< endl;
       s.pop();
       h++;
  } 
  cout<<"h="<<h<<endl; 
  
  printf("Time : %.6fs \n",tEnd);
}