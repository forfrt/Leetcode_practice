#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target);

int main(int argc, char **argv){
    vector<int> v={1, 3, 6, 8, 14, 19, 20, 23, 25};
    int target=23;
    
    vector<int> res=twoSum(v, target);
    for(int n:res){
        printf("%d\n", n);
    }

}

vector<int> twoSum(vector<int> &numbers, int target){
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;

    for(int i=0; i<numbers.size(); i++){
        int numberToFind=target-numbers[i];

        //if numberToFind is found in map, return them
        if(hash.find(numberToFind)!=hash.end()){
            result.push_back(hash[numberToFind]+1);
            result.push_back(i+1);

            return result;
        }

        hash[numbers[i]]=i;
    }
    return result;
}
