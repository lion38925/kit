class Solution {
public:
    double area(vector<int> p1,vector<int> p2,vector<int> p3){
        double a=sqrt((p2[1]-p1[1])*(p2[1]-p1[1])+(p2[0]-p1[0])*(p2[0]-p1[0]));
        double b=sqrt((p3[1]-p1[1])*(p3[1]-p1[1])+(p3[0]-p1[0])*(p3[0]-p1[0]));
        double c=sqrt((p3[1]-p2[1])*(p3[1]-p2[1])+(p3[0]-p2[0])*(p3[0]-p2[0]));
        double s=(a+b+c)/2;
        return sqrt(s*(s-b)*(s-c)*(s-a));
        
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double max=INT_MIN;
        for(int i=0;i<points.size();i++)
            for(int j=0;j<points.size();j++)
                for(int k=0;k<points.size();k++)
                {
                    double a=area(points[i],points[j],points[k]);
                    if(a>max)
                        max=a;
                }
        return max;
    }
};