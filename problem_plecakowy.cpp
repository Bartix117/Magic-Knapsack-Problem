#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Item
{
    int id;
    int weight;
    int value;
};

void KnapsackWithMagicSpheres(int capacity, std::vector<Item> items, int M, int sphere_weight)
{
    int n=items.size();

    std::vector<std::vector<int>> dp(n+1,std::vector<int>(capacity + 1, 0));

    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=capacity;w++)
        {
            if(items[i-1].weight<=w)
            {
                dp[i][w]=std::max(dp[i-1][w],dp[i-1][w-items[i-1].weight]+items[i-1].value);
            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    long long max_value=-1;
    int how_many_spheres=0;
    int max_remaining_space=0;

    for(int k=0;k<=M;k++)
    {
        int spheres_weight=k*sphere_weight;

        if(spheres_weight<=capacity)
        {
            int remaining_space=capacity-spheres_weight;

            long long current_value=static_cast<long long>(dp[n][remaining_space])*std::pow(2,k);

            if(current_value>max_value)
            {
                max_value=current_value;
                how_many_spheres=k;
                max_remaining_space=remaining_space;
            }
        }
    }

    std::vector<int> selected_id;
    int current_capacity= max_remaining_space;

    for(int i=n;i>0&& current_capacity>0;i--)
    {
        if(dp[i][current_capacity]!=dp[i-1][current_capacity])
        {
            selected_id.push_back(items[i-1].id);
            current_capacity -= items[i-1].weight;
        }
    }

    std::cout << "Max value: " << max_value << "\n";
    std::cout << "Used magic spheres: " << how_many_spheres << "\n";
    std::cout << "Selected items (ID): ";
    if(selected_id.empty()) {
        std::cout << "No items\n";
    } else {
        
        std::sort(selected_id.begin(), selected_id.end());
        for(int i = 0; i < selected_id.size(); i++) {
            std::cout << selected_id[i] << " ";
        }
        std::cout << "\n";

    }

}


int main()
{
    int backpack_capacity = 11;
    
    std::vector<Item> items1 = {
        {1, 9, 12},
        {2, 5, 8},
        {3, 3, 5}
    };
    
    int max_spheres = 3;       
    int sphere_weight = 2;     


    KnapsackWithMagicSpheres(backpack_capacity, items1, max_spheres, sphere_weight);

    return 0;
}