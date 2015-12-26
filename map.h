#ifndef MAP_H
#define MAP_H


class map
{
    public:
        map();
        ~map();
        map(const map& other);
        map& operator=(const map& other);

        int** Getgrid() { return grid; }
        void Setgrid(int** val) { grid = val; }

    protected:

    private:
        int** grid;
};

#endif // MAP_H
