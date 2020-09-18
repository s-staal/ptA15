#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//Extracts contents of file
void extract_list(string filename, vector<pair<string, float>> &list);
//Merges the content of vectors a and b alphabetically into merged
void merge_items(vector<pair<string, float>> &merged, vector<pair<string, float>> const &a, vector<pair<string, float>> const &b);

int main()
{
    //Obtain user input
    string file1, file2;
    cout<<"Please input the filenames"<<endl;
    cin>>file1>>file2;

    //Extracts files into vectors
    vector<pair<string, float>> list1, list2;
    extract_list(file1, list1);
    extract_list(file2, list2);

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

void extract_list(string filename, vector<pair<string, float>> &list)
{
    ifstream ifs (filename, ifstream::in);
    //Ensures file is valid
    if(!ifs.good()){
      cerr<<"File "<<filename<<" is invalid"<<endl;
      exit(1);
    }
    while(1){
        if(ifs.eof()){
            ifs.close();
            return;
        }
        string name;
        float value;
        ifs>>name>>value;
        list.push_back({name, value});
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
        if(a_name < b_name){
          merged.push_back(a[i]);
          i++;
        }
        if(a_name > b_name){
          merged.push_back(b[j]);
          j++;
        }
        if(a_name == b_name){
          merged.push_back({a[i].first, a[i].second+b[j].second});
          i++;
          j++;
        }
    }
    return;
}
