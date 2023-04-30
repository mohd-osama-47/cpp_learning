#include <vector>
#include <iostream>

/// @brief This class implements the QUICK FIND method
class QuickUnionFind1
{
public:
    std::vector<int> roots;
    QuickUnionFind1();
    
    /// @brief Constructor, generates a roots vector of all nodes given the input size
    /// @param size 
    QuickUnionFind1(int size)
    {
        // Update the roots vector to have each element be it's own parent
        this->roots = std::vector<int>(size);
        for (int i{0}; i < size; i++)
        {
            this->roots[i] = i;
        }
    }

    /// @brief Find the root of the given index
    /// @param index input index to check
    /// @return 
    int find(int index)
    {
        if (index > this->roots.size()) return -1;
        return this->roots[index];
    }

    /// @brief Creates a union of two graph nodes based on their roots
    /// @param id1 first node to check
    /// @param id2 second node to check
    void join(int id1, int id2)
    {
        int root1 = this->roots[id1];
        int root2 = this->roots[id2];
        if (root1 != root2)
        {
            for (int i{0}; i < this->roots.size(); i++)
            {
                if (this->roots[i] == root2)
                {
                    roots[i] = root1;
                }
            }
        }
    }

    /// @brief 
    /// @param id1 
    /// @param id2 
    /// @return 
    bool isConnected(int id1, int id2)
    {
        return find(id1) == find(id2);
    }
};




/// @brief This class implements the QUICK UNION method
class QuickUnionFind2
{
public:
    std::vector<int> roots;
    QuickUnionFind2();
    
    /// @brief Constructor, generates a roots vector of all nodes given the input size
    /// @param size 
    QuickUnionFind2(int size)
    {
        // Update the roots vector to have each element be it's own parent
        this->roots = std::vector<int>(size);
        for (int i{0}; i < size; i++)
        {
            this->roots[i] = i;
        }
    }

    /// @brief Find the root of the given index
    /// @param index input index to check
    /// @return 
    int find(int index)
    {
        // Continue traveling up the roots vector until you find
        // the root (root is when parent is the node itself)
        while (index != this->roots[index])
        {
            index = this->roots[index];
        }
        return index;
    }

    /// @brief Creates a union of two graph nodes based on their roots
    /// @param id1 first node to check
    /// @param id2 second node to check
    void join(int id1, int id2)
    {
        int root1 = find(id1);
        int root2 = find(id2);
        if (root1 != root2)
        {
            // in this case, just change the parent of the second node
            // to be the root of the first node
            this->roots[root2] = root1;
        }
    }

    /// @brief 
    /// @param id1 
    /// @param id2 
    /// @return 
    bool isConnected(int id1, int id2)
    {
        // need to check if BOTH have the same root
        // use find function
        return find(id1) == find(id2);
    }
};


/// @brief This class implements the QUICK UNION + UNION BY RANK method
class QuickUnionFind3
{
public:
    std::vector<int> roots;
    std::vector<int> rank;
    QuickUnionFind3();
    
    /// @brief Constructor, generates a roots vector of all nodes given the input size
    /// @param size 
    QuickUnionFind3(int size)
    {
        // Update the roots vector to have each element be it's own parent
        this->roots = std::vector<int>(size);
        // Create the rank vector and init all vals with 1
        this->rank = std::vector<int>(size, 1);
        for (int i{0}; i < size; i++)
        {
            this->roots[i] = i;
        }
    }

    /// @brief Find the root of the given index
    /// @param index input index to check
    /// @return 
    int find(int index)
    {
        // Continue traveling up the roots vector until you find
        // the root (root is when parent is the node itself)

        // same find as quick union, no change
        while (index != this->roots[index])
        {
            index = this->roots[index];
        }
        return index;
    }

    /// @brief Creates a union of two graph nodes based on their roots
    /// @param id1 first node to check
    /// @param id2 second node to check
    void join(int id1, int id2)
    {
        int root1 = find(id1);
        int root2 = find(id2);
        if (root1 != root2)
        {
            // instead of changing root of id2 to be root1,
            // merge based on the RANK:
            if (this->rank[root1] > this->rank[root2])
            {
                // prioritize root 1 since adding children to it 
                // will NOT change the height of the graph
                this->roots[root2] = root1;
            }
            else if (this->rank[root1] < this->rank[root2])
            {
                // prioritize root 2 since adding children to it 
                // will NOT change the height of the graph
                this->roots[root1] = root2;
            }
            else
            {
                // Chose any one since they have the same rank
                // BUT increase the rank of the new root!
                this->roots[root2] = root1;
                this->rank[root1]++;
            }
        }
    }

    /// @brief 
    /// @param id1 
    /// @param id2 
    /// @return 
    bool isConnected(int id1, int id2)
    {
        // need to check if BOTH have the same root
        // use find function
        return find(id1) == find(id2);
    }
};

/// @brief This class implements the QUICK UNION + UNION BY RANK + PATH COMPRESSION IN FIND() CALL method
class QuickUnionFind4
{
public:
    std::vector<int> roots;
    std::vector<int> rank;
    QuickUnionFind4();
    
    /// @brief Constructor, generates a roots vector of all nodes given the input size
    /// @param size 
    QuickUnionFind4(int size)
    {
        // Update the roots vector to have each element be it's own parent
        this->roots = std::vector<int>(size);
        // Create the rank vector and init all vals with 1
        this->rank = std::vector<int>(size, 1);
        for (int i{0}; i < size; i++)
        {
            this->roots[i] = i;
        }
    }

    /// @brief Find the root of the given index
    /// @param index input index to check
    /// @return 
    int find(int index)
    {
        // Continue traveling up the roots vector until you find
        // the root (root is when parent is the node itself)

        // Now, update all traversed element's parent to be
        // new root through recursion
        if (this->roots[index] == index) return index;
        return this->roots[index] = find(this->roots[index]);
    }

    /// @brief Creates a union of two graph nodes based on their roots
    /// @param id1 first node to check
    /// @param id2 second node to check
    void join(int id1, int id2)
    {
        int root1 = find(id1);
        int root2 = find(id2);
        if (root1 != root2)
        {
            // instead of changing root of id2 to be root1,
            // merge based on the RANK:
            if (this->rank[root1] > this->rank[root2])
            {
                // prioritize root 1 since adding children to it 
                // will NOT change the height of the graph
                this->roots[root2] = root1;
            }
            else if (this->rank[root1] < this->rank[root2])
            {
                // prioritize root 2 since adding children to it 
                // will NOT change the height of the graph
                this->roots[root1] = root2;
            }
            else
            {
                // Chose any one since they have the same rank
                // BUT increase the rank of the new root!
                this->roots[root2] = root1;
                this->rank[root1]++;
            }
        }
    }

    /// @brief 
    /// @param id1 
    /// @param id2 
    /// @return 
    bool isConnected(int id1, int id2)
    {
        // need to check if BOTH have the same root
        // use find function
        return find(id1) == find(id2);
    }
};

int main()
{
    // for displaying booleans as literal strings, instead of 0 and 1
    std::cout << std::boolalpha;
    QuickUnionFind4 uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.join(1, 2);
    uf.join(2, 5);
    uf.join(5, 6);
    uf.join(6, 7);
    uf.join(3, 8);
    uf.join(8, 9);
    std::cout << uf.isConnected(1, 5) << std::endl;  // true
    std::cout << uf.isConnected(5, 7) << std::endl;  // true
    std::cout << uf.isConnected(4, 9) << std::endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.join(9, 4);
    std::cout << uf.isConnected(4, 9) << std::endl;  // true

    return 0;
}