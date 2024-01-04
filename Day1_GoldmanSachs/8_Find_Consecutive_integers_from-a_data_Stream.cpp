class DataStream
{
private:
    int v = 0;
    int limit = 0;
    int count = 0;

public:
    DataStream(int value, int k)
    {
        v = value;
        limit = k;
    }

    bool consec(int num)
    {
        if (num == v)
        {
            count++;
            if (count >= limit)
                return true;
            else
                return false;
        }
        else
            count = 0;
        return false;
    }
};

