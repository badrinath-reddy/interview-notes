#include <iostream>

using namespace std;

class File {
public:
    string name;
    string extention;
    int size;
    
    File(string name, string extention, int size) {
        this->name = name;
        this->extention = extention;
        this->size = size;
    }
};


class Directory {
public:
    string name;
    vector<File* > files;
    vector<Directory *> directories;
    
    Directory(string name,  vector<File* > files, vector<Directory *> directories) {
        this->name = name;
        this->files = files;
        this->directories = directories;
    }
    
};


class FileFilter {
public:
    virtual bool isValid(File *file) = 0;
};

class AndFilter : public FileFilter {
    
    FileFilter *filter1;
    FileFilter *filter2;
public:
    
    AndFilter(FileFilter *filter1, FileFilter *filter2) {
        this->filter1 = filter1;
        this->filter2 = filter2;
    }
    
    bool isValid(File *file) {
        return filter1->isValid(file) and filter2->isValid(file);
    }
    
};

class OrFilter : public FileFilter {
    
    FileFilter *filter1;
    FileFilter *filter2;
public:
    
    OrFilter(FileFilter *filter1, FileFilter *filter2) {
        this->filter1 = filter1;
        this->filter2 = filter2;
    }
    
    bool isValid(File *file) {
        return filter1->isValid(file) or filter2->isValid(file);
    }
};


class FileExtentionFilter: public FileFilter {
    string fileExtention;
    
public:
    
    FileExtentionFilter(string fileExtention) {
        this->fileExtention = fileExtention;
    }
    
    
    bool isValid(File *file) {
        if(file->extention == fileExtention) {
            return true;
        }
        return false;
    }
    
};


class FileSearch {
    
    Directory *directory;
    FileFilter *fileFilter;
    
public:
    
    FileSearch(Directory *directory, FileFilter *fileFilter) {
        this->directory = directory;
        this->fileFilter = fileFilter;
    }
    
    
    
};

vector<File*> find(Directory *directory, FileFilter *fileFilter) {
    
    vector<File *> ans;
    
    for(auto &x: directory->directories) {
        auto temp = find(x, fileFilter);
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    
    for(auto &x: directory->files) {
        if(fileFilter->isValid(x)) {
            ans.push_back(x);
        }
    }
    
    return  ans;
};





int main(int argc, const char * argv[]) {
    
    File *file = new File("Hello.csv", ".csv", 1);
    FileFilter *fileFilter = new FileExtentionFilter(".csv");
    
    Directory *dir = new Directory("/", {file}, {});
    
    auto ans = find(dir, fileFilter);
    
    
    for(auto x: ans) {
        cout << x->name << endl;
    }
    
    return 0;
}
