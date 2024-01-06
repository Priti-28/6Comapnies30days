class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                // distance between points and centers
                double dis = pow((i - xCenter), 2) + pow((j - yCenter), 2);
                double r = radius * radius;

                // distance distance between each points and the radius
                // if distance between any point is less than radius then overlapping
                if (dis <= r)
                    return true; // both side of squares will cancel out while comparing
            }
        }
        return false;
    }
};