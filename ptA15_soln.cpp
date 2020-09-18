#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//Merges the content of vectors a and b alphabetically into merged
void merge_items(vector<pair<string, float>> &merged, vector<pair<string, float>> const &a, vector<pair<string, float>> const &b);

int main()
{
    //Obtain user input
    string file1, file2;
    cout<<"Please input the filenames"<<endl;
    cin>>file1>>file2;

    //Input processing
    vector<pair<string, float>> list1, list2;
    //Ensures files are valid
    ifstream l1 (file1, ifstream::in);
    if(!l1.good()){
      cerr<<"File 1 is invalid (filename: "<<file1<<")"<<endl;
      return 1;
    }
    ifstream l2 (file2, ifstream::in);
    if(!l2.good()){
      cerr<<"File 2 is invalid (filename: "<<file2<<")"<<endl;
      return 2;
    }

    //Extracts files into vectors
    while(!l1.eof()){
        string name;
        float value;
        l1>>name>>value;
        list1.push_back({name, value});
    }
    l1.close();

    while(!l2.eof()){
        string name;
        float value;
        l2>>name>>value;
        list2.push_back({name, value});
    }
    l2.close();

    //Checks for empty inputs
    if(list1[0].first.empty() && list2[0].first.empty()){
      return 0;
    }
    if(list1[0].first.empty()){
      for(int i = 0; i < list2.size(); i++){
        cout<<list2[i].first<<" "<<list2[i].second<<endl;
      }
      return 0;
    }
    if(list2[0].first.empty()){
      for(int i = 0; i < list1.size(); i++){
        cout<<list1[i].first<<" "<<list1[i].second<<endl;
      }
      return 0;
    }

    //Merges vectors into 1 sorted vector
    vector<pair<string, float>> merged;
    merge_items(merged, list1, list2);

    //Prints the output of the vector
    for(int i = 0; i < merged.size(); i++){
        cout<<merged[i].first<<" "<<merged[i].second<<endl;
    }

}

void merge_items(vector<pair<string, float>> &merged, vector<pair<string, float>> const &a, vector<pair<string, float>> const &b)
{
    int i = 0, j = 0;
    while(i < a.size() || j < b.size()){
        string a_name, b_name;
        //If the end of the vector is reached, the name is replaced by an ASCII character with a value higher than any letter
        if(i == a.size()){
          a_name = "~";
        }
        else{
          a_name = a[i].first;
        }
        if(j == b.size()){
          b_name = "~";
        }
        else{
          b_name = b[j].first;
        }
        //Places elements into new vector in alphabetical order
        if(a_name < b_name){
          merged.push_back(a[i]);
          i++;
        }
        if(a_name > b_name){
          merged.push_back(b[j]);
          j++;
        }
        //If elements match, values are added together
        if(a_name == b_name){
          merged.push_back({a[i].first, a[i].second+b[j].second});
          i++;
          j++;
        }
    }
    return;
}
