#include <iostream>
using namespace std;
static int playlistCount = 0;
static int songCount = 0;
static float duration_time = 0;

class Song
{
private:
    string title;
    string artist;
    float duration;

public:
    Song() {}
    Song(string t, string a, float d) : title(t), artist(a), duration(d) {}
    string getTitle() const
    {
        return title;
<<<<<<< HEAD
    }
    string getArtist() const 
=======
    } 
    string getArtist() const
>>>>>>> db48d9cd7d939c1e2a486578a946f65555fffc34
    {
        return artist; 
    }
    int getDuration() const
    {
        return duration;
    }
    void show()
    {
        cout << "Title of Song is : " << title << endl;
        cout << "artist of Song is : " << artist << endl;
        cout << "durationd of Song is : " << duration << " s" << endl;
    }
    void addsong()
    {
        cout << "Title of Song is : ";
        cin >> title;
        cout << endl;
        cout << "artist of Song is : ";
        cin >> artist;
        cout << endl;
        cout << "durationd of Song is : ";
        cin >> duration;
        cout << endl;
        duration_time = duration_time + duration;
    }
};

class Playlist
{
private:
    string playlist_name;
    Song s;
    Song songs[3];
    int songlimit;

public:
    Playlist() {}
    Playlist(string p, string t, string a, float d) : playlist_name(p), s(t, a, d) {}
    void create()
    {
        string name;
        cout << "Enter playlist name : ";
        cin >> name;
        playlist_name = name;
        cout << "How many songs do you to want : ";
        cin >> songlimit;
        cout << endl;
        if (songlimit > 3)
        {
            cout << "You cannot make upto 3 playlists " << endl;
            return;
        }
        if (songCount < 5)
        {
            for (int i = 0; i < songlimit; i++)
            {
                songs[i].addsong();
            }
            songCount++;
        }
        else
        {
            cout << "Maximum number of playlists reached." << endl;
        }
    }
    void print()
    {
        cout << "----------------------------------" << endl;
        cout << "Name of Playlist is : " << playlist_name << endl;
        cout << "----------------------------------" << endl;

        for (int J = 0; J < songlimit; J++)
        {
            songs[J].show();
            cout << "----------------------------------" << endl;
        }
    }
    void print4P()
    {
        cout << "----------------------------------" << endl;
        cout << "Name of Playlist is : " << playlist_name << endl;
        cout << "----------------------------------" << endl;
        cout << "Title of Song is : " << s.getTitle() << endl;
        cout << "artist of Song is : " << s.getArtist() << endl;
        cout << "durationd of Song is : " << s.getDuration() << " s" << endl;
        cout << "----------------------------------" << endl;
    }
};

class User
{
private:
    string username;
    Playlist playlists[2];
    Playlist P;
    int listlimit;

public:
    User(string user_name) : username(user_name) {}
    User(string user_name, string p, string t, string a, float d) : username(user_name), P(p, t, a, d)
    {
        cout << "User Constructor invoke " << endl;
    }
    void createPlaylist()
    {
        cout << "How many Playlist do you want : ";
        cin >> listlimit;
        cout << endl;
        if (listlimit > 2)
        {
            cout << "You cannot make upto 2 playlists " << endl;
            return;
        }

        if (playlistCount < 2)
        {
            for (int i = 0; i < listlimit; i++)
            {
                playlists[playlistCount].create();
                playlistCount++;
            }
        }
        else
        {
            cout << "Maximum number of playlists reached." << endl;
        }
    }

    void Display()
    {
        cout << "Name of user is : " << username << endl;
        for (int j = 0; j < listlimit; j++)
        {
            playlists[j].print();
        }
        cout << "Total time duration  is : " << duration_time << " s" << endl;
    }
    ~User()
    {
        cout << "User destructor invoke " << endl;
    }
};

int main()
{
    Playlist *p = new Playlist("Soul", "mind", "game", 3.4);
    User obj_u("zain", "Soul", "mind", "game", 3.4);
    cout << "----------------------------------" << endl;
    obj_u.createPlaylist();
    cout << "----------------------------------" << endl;
    obj_u.Display();
    cout << "----------------------------------" << endl;
    cout << "Values of *p that is set by me" << endl;
    p->print4P();
    delete p;
    return 0;
}
