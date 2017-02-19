#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;



class HTMLElement
{
    unsigned width;
    unsigned height;
    bool hidden;
public:
    HTMLElement():width(0), height(0), hidden(true)   {}
    HTMLElement(unsigned W, unsigned H, bool hid): width(W),height(H),hidden(hid)   {}
    virtual ~HTMLElement() {}
    unsigned int Width() const
    {
        return width;
    }
    unsigned int Height() const
    {
        return height;
    }
    bool Hidden() const;

    virtual string Render()=0;

};

class HTMLButtonElement : public HTMLElement
{
    string TITLE;
public:
    HTMLButtonElement() : HTMLElement(), TITLE("title-of-the-button")   {}
    HTMLButtonElement(unsigned w, unsigned h, bool hid, string title) : HTMLElement(w,h,hid), TITLE(title)  {}
    ~HTMLButtonElement() {}

    const string& Title() const
    {
        return TITLE;
    }
    string Render() override
    {
        return "<button>" + TITLE + "</button>";
    }
};

class HTMLImageElement : public HTMLElement
{
    string URL;
public:
    HTMLImageElement() : HTMLElement()  {}
    HTMLImageElement(unsigned w, unsigned h, bool hid, string url) : HTMLElement(w,h,hid), URL(url) {}
    ~HTMLImageElement() {}

    const string& Url() const;
    string Render() override
    {
        string width = to_string(Width());
        string heig = to_string(Height());
        string ret_info = "<img src = \"" + URL + "\" " + "Height = \"" + heig + "\" width = \"" + width + "\">";
        return ret_info;
    }
};

class HTMLTextAreaElement : public HTMLElement
{
    string TEXT;
public:
    HTMLTextAreaElement() : HTMLElement(), TEXT("content-of-the-text-area") {}
    HTMLTextAreaElement(string text) : HTMLElement(100, 50, true), TEXT(text) {}
    HTMLTextAreaElement(unsigned w, unsigned h, bool hid, string text) : HTMLElement(w,h,hid), TEXT(text) {}
    ~HTMLTextAreaElement() {}

    const string& Content() const
    {
        return TEXT;
    }
    string Render() override
    {
        string ret_info = "<textarea>\n" + TEXT + "\n</textarea>";
        return ret_info;
    }
};

string get_render(HTMLElement &obj)
{
    return obj.Render();
}

int main(int argc, char *argv[])
{

HTMLButtonElement obj1;
HTMLImageElement obj2;
HTMLTextAreaElement obj3;

HTMLElement *qwe = new HTMLButtonElement;

cout << get_render(*qwe) << endl;
cout << get_render(obj1) << endl;
cout << get_render(obj2) << endl;
cout << get_render(obj3) << endl;



    return 0;
}


