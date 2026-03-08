#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node* left;
    Node* right;
    double rating;
    vector<string> movies;
    Node(double r)
    {
        rating = r;
        left = NULL;
        right = NULL;
    }
};

class Movie_Rating_Management_System
{
    public:
    Node* root;
    unordered_map<string,int> reg;
    int total_rating = 0,total_movie = 0;
    Movie_Rating_Management_System()
    {
        root = NULL;
    }

    double get_valid_d()
    {
        double r;
        while(true)
        {
            cin>>r;
            if(cin.fail())
            {
                cout<<"Invalid input , Enter a decimal: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }else if(r>10.0 || r<0.0)
            {
                cout<<"Enter a valid rating(0-10) : ";    
            }
            else
            {
                break;
            }
        }
        return r;
    }

    int get_menu_int()
    {
        int x;
        while(true)
        {
            cin>>x;
            if(cin.fail())
            {
                cout<<"Invalid input , Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }else { break; } 
        }
        return x;
    }

    int get_movie_int()
    {
        int x;
        while(true)
        {
            cin>>x;
            if(cin.fail())
            {
                cout<<"Invalid input , Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }else if(x>20 || x<=0)
            {
                cout<<"Enter a value from the range 1-20 :";
                continue;
            }else { break; } 
        }
        return x;
    }
    
    char get_valid_char()
    {
        char x;
        while(true)
        {
            cin>>x;
            if(cin.fail())
            {
                cout<<"Invalid input , Enter a character: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }else
            {
                break;
            }
        }
        return x;
    }

    string get_valid_string()
    {
        string x;
        getline(cin>>ws,x);
        return x;
    }

    Node* create_node(double rate)
    {
        total_rating += 1;
        Node* newnode = new Node(rate);
        string name;
        cout<<"How many movie(s) you want to add(range->1-20):";
        int num = get_movie_int();
        total_movie += num;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        while(num>0)
        {
            cout<<"Enter movie name:";
            getline(cin,name);
            if(reg[name]!=0)
            {
                cout<<"Movie already exists , ";
                continue;
            }
            newnode->movies.push_back(name);
            reg[name]++;
            cout<<"Movie added successfully.\n";
            num--;
        }
        reg_cleaner();
        return newnode;
    }

    void add_movie_to_existing_rating(double rate)
    {
        Node* temp = root;
        while(abs(temp->rating-rate)>0.0001)
        {
            if(temp->rating>rate)
            {
                temp=temp->left;
            }else if(temp->rating<rate)
            {
                temp=temp->right;
            }
        }
        string name;
        cout<<"Enter number of movies to add: ";
        int num = get_movie_int();
        total_movie += num;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        while(num>0)
        {
            cout<<"Enter movie name:";
            getline(cin,name);
            if(reg[name]!=0)
            {
                cout<<"Movie already exists , Enter a new movie : ";
                continue;
            }
            temp->movies.push_back(name);
            reg[name]++;
            cout<<"Movie added successfully.\n";
            num--;
        }
        reg_cleaner();
        return;
    }

    bool search(Node* checker,double rate)
    {
        if(checker==NULL){return false;}
        if(abs(checker->rating-rate)<0.0001){return true;}
        else if(checker->rating<rate)
        {
            return search(checker->right,rate);
        }else
        {
            return search(checker->left,rate);
        }
    }

    Node* findMin(Node* current)
	{
		while(current!=NULL && current->left!=NULL)
		{
			current=current->left;
		}
		return current;
	}

    Node* delete_node(Node* current,double key)
    {
        if(current==NULL) return NULL;
		if(key<current->rating)
		{
			current->left = delete_node(current->left,key);
		}
		else if(key>current->rating)
		{
			current->right = delete_node(current->right,key);
		}
		else
        {
            Node* temp = NULL;
            if(current->left==NULL && current->right==NULL)
            {
                delete current;return NULL;
            }
            else if(current->left==NULL)
            {
                temp = current->right;
                delete current;
                return temp;
            }
            else if(current->right==NULL)
            {
                temp = current->left;
                delete current;
                return temp;
            }
            else
            {
                temp = findMin(current->right);
                current->rating = temp->rating;
                current->movies = temp->movies;
                current->right = delete_node(current->right,temp->rating);
            }
        }
        return current;
    }

    void delete_node_fully(Node* temp)
    {
        root = delete_node(root,temp->rating);
        return;
    }

    void add_movie()
    {
        cout<<"Enter rating:";
        double rate = get_valid_d();
        if(root==NULL)
        {
            root = create_node(rate);
            return;
        }
        if(search(root,rate))
            {
                cout<<"Rating exists\nDo you want to add movie(s) to this rating?(y/n)\n";
                char c = get_valid_char();
                if(c=='y' || c=='Y')
                {
                    add_movie_to_existing_rating(rate);
                }
                return;
            }
        else
            {
                Node* d1 = create_node(rate);
                insert_node(d1);
            }
        return;
    }

    void insert_node(Node* temp)
    {
        root = insert(root,temp);
        return;
    }

    Node* insert(Node* root,Node* newnode)
    {
        if(root==NULL)
        {
            return newnode;
        }
        if((newnode->rating)<(root->rating - 0.0001))
        {
            root->left = insert(root->left,newnode);
        }else if((newnode->rating)>(root->rating + 0.0001))
        {
            root->right = insert(root->right,newnode);
        }
        return root;
    }

    Node* finding_node_of_rate(Node* temp,double rate)
    {
        if(temp==NULL) return NULL;
        if(abs(temp->rating-rate)<0.0001){return temp;}
        else if(temp->rating>rate)
        {
            return finding_node_of_rate(temp->left,rate);
        }else
        {
            return finding_node_of_rate(temp->right,rate);
        }
    }
    
    void deletion()
    {
        double rate;
        cout<<"Enter rating:";
        rate = get_valid_d();
        if(!search(root,rate))
        {
            cout<<"Rating not found\n";
            return;
        }
        Node* del = finding_node_of_rate(root,rate);
        cout<<"Movies under this rating:\n";
        display_movies(del->movies);
        string m;
        cout<<"Enter movie name to delete:";
        m = get_valid_string();
        int j=0;
        bool got = false;
        for(int i=0;i<del->movies.size();i++)
        {
            if(del->movies[i]==m)
            {
                got = true;
                j = i+1;
                break;
            }
        }
        if(!got)
        {
            cout<<"Movie not found";
            return;
        }
        del->movies.erase(del->movies.begin()+j-1);
        reg[m]--;
        cout<<"Movie deleted successfully\n";
        total_movie -= 1;
        if(del->movies.size()==0)
        {
            total_rating -= 1;
            delete_node_fully(del);
        }
        reg_cleaner();
        return;        
    }

    void display_movies(const vector<string>& movies)
    {
        for(int i=0;i<movies.size();i++)
        {
            cout<<"  "<<i+1<<". "<<movies[i]<<endl;
        }
        return;
    }

    void Minimum_rating()
    {
        Node* temp = root;
        if(root==NULL)
        {
            cout<<"No ratings available\n";return;
        }
        while(temp!=NULL && temp->left!=NULL)
        {
            temp=temp->left;
        }
        cout<<"Minimum rating:"<<temp->rating<<endl;
        cout<<"Movies under this rating:\n";
        display_movies(temp->movies);
        return;
    }

    void Maximum_rating()
    {
        Node* temp = root;
        if(root==NULL)
        {
            cout<<"No ratings available\n";return;
        }
        while(temp!=NULL && temp->right!=NULL)
        {
            temp=temp->right;
        }
        cout<<"Maximum rating:"<<temp->rating<<endl;
        cout<<"Movies under this rating:\n";
        display_movies(temp->movies);
        return;
    }

    void in_order_traverse(Node* temp)
    {
        if(temp!=NULL)
        {
            in_order_traverse(temp->left);
            cout<<" Rating - "<<temp->rating<<endl;
            cout<<" Movie/Movies under this rating:"<<endl;
            display_movies(temp->movies);
            in_order_traverse(temp->right);
        }
    }

    void display()
    {
        if(root==NULL){cout<<"Empty record"<<endl;return;}
        cout<<"Movies rating:\n-----------------------------------"<<endl;
        in_order_traverse(root);
        cout<<"-----------------------------------"<<endl;
        cout<<" Total rating(s) : "<<total_rating<<endl;
        cout<<" Total movie(s)  : "<<total_movie<<endl;
        cout<<"-----------------------------------"<<endl;
    }

    void reg_cleaner()
    {
        for(auto it:reg)
        {
            if(it.second==0) reg.erase(it.first);
        }
        return;
    }

    void ultimate_menu(int user_input)
    {
        while(user_input!=6)
    {
        cout<<"\n1.Add a movie\n2.Delete a movie\n3.Show all movie ratings\n4.Minimum rating movie(s)\n5.Maximum rating movie(s)\n6.Exit"<<endl;
        cout<<"Choose an option:";
        user_input = get_menu_int();
        if(user_input==6){break;}
        switch(user_input)
        {
            case 1:add_movie();
                    break;
            case 2:deletion();
                    break;
            case 3:display();
                    break;
            case 4:Minimum_rating();
                    break;
            case 5:Maximum_rating();
                    break;
            default:cout<<"Please,choose a valid option"<<endl;break;
        }
    }
    cout<<"Thank you for using our system\nDo visit again";
    return;
    }
};

int main()
{
    cout<<"\nMovie Rating Management System\n";
    Movie_Rating_Management_System mrms;
    mrms.ultimate_menu(0);
    return 0;
}
