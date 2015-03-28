#include <list>
#include <string>
#include <iostream>
using namespace std;

class Component
{
public:
		Component(string _name)
		{
			this->name = name;
		}

		virtual void add(Component& c){}
		virtual void remove(Component& c){}
		virtual void display(int depth){}

protected:
		string name;
};

class Leaf : public Component
{
public:
		Leaf(string name) : Component(name)
		{
		}

		virtual void add(Component& c)
		{
			cout << "cannot add to a leaf!"	<< endl;
		}

		virtual void remove(Component& c)
		{
			cout << "cannot remove to a leaf!"	<< endl;
		}

		virtual void display(int depth)
		{
			cout << "-" << depth << name;
		}
};

class Composite : public Component
{
public:
		Composite(string name) : Component(name)
		{
		}

		virtual void add(Component& c)
		{
				child.insert(c);
		}

		virtual void remove(Component& c)
		{
			child.erase(c);
		}

		virtual void display(int depth)
		{
			cout << "-" << depth << name;
		
			for(auto iter = child.begin(); iter != child.end(); ++iter)
			{
				*iter.display(depth + 2);
			}
		}

private:
		list<Component> child;
};

int main()
{
	Composite() root("root");
	Leaf a("Leaf A");
	Leaf b("Leaf B");
	root.add(a);
	root.add(b);

	Composite comp("Composite X");
	Leaf xa("Leaf XA");
	Leaf xb("Leaf XB");
	root.add(comp);

	Composite comp2("Composite XY");
	Leaf xya("Leaf XYA");
	Leaf xyb("Leaf XYB");
	comp.add(comp2);
		
	Leaf c("Leaf C");
	root.add(c);

	root.display(1);
	return 0;
}
