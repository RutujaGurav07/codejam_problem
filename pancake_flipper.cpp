#include <iostream>

using namespace std;
class node
{
public:
  char data;
  node *next;
  friend class linklist;
};
class linklist
{
public:
  int k;
  string a;
  node *head;

    linklist ()
  {
    head = NULL;
    a = "\0";
    k = 0;
  }

  node *add (char i);
  node *insert (string a);
  void print ();
  int flip (int k, string a);
  void input ();
};

void
linklist::input ()
{
  cout << "Enter a string : ";
  cin >> a;
  cout << "Enter  flutter count: ";
  cin >> k;

}

int
linklist::flip (int k, string a)
{
  int len;
  int counter = 0;
  node *temp;
  len = a.size ();
  temp = head;
  int i;
  while (temp != NULL)
    {
      if (temp->data == '-')
{
 for (i = 0; i < k && temp != NULL; i++)
   {
     if (temp->data == '-')
{

 temp->data = '+';
}
     else
{
 temp->data = '-';
}
     temp = temp->next;
   }
 if (i != k)
   {
     return -1;
   }
 counter++;
 if (counter > len)
   {
     return -1;
   }
 temp = head;
}
      temp = temp->next;
    }
  return counter;
}

node *
linklist::add (char data)
{
  node *newnode = new node;
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

node *
linklist::insert (string a)
{
  head = add (a[0]);
  node *curr = head;

  // curr pointer points to the current node
  // where the insertion should take place
  for (int i = 1; i < a.size (); i++)
    {
      curr->next = add (a[i]);
      curr = curr->next;
    }
  return head;
}

void
linklist::print ()
{
  node *t;
  t = head;
  while (t->next != NULL)
    {
      cout << t->data << " ";
      t = t->next;
    }
  cout << "\n";
}

int
main ()
{
  int n;
  linklist l[n];
  int i, h;
  cout << "Enter number of testcase : ";
  cin >> n;

  for (h = 0; h < n; h++)
    {

      l[h].input ();
      l[h].insert (l[h].a);
      l[h].print ();
    }
  for (h = 0; h < n; h++)
    {
      int p = l[h].flip (l[h].k, l[h].a);
      if (p == -1)
{
 cout << "\ncase#" << h + 1 << " impossible\n";
}
      else
{
 cout << "\ncase#" << h + 1 << " " << p << endl;
}

    }
}
