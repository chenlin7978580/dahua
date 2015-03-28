//构造函数可以是虚函数呢？在构造函数中调用虚函数会有什么样的结果？ 很正常啊！！！

#include <iostream>
using namespace std;

class INode
{
		public:
				INode(int i) : inode(i)
				{ cout << "Create: I am INode!" << endl;}
				virtual ~INode(){ cout << "Dlete: I am INode!" << endl; }
		public:
				virtual void display(){ cout << "INode: " << inode << endl; }

		private:
				int inode;
};

class DINode : public INode
{
	public:
			DINode(int i, int j) : node(i), INode(j)
			{ cout << "Create: I am DINode!" << endl;}
			~DINode(){ cout << "Dlete: I am DINode!" << endl; }
	public:
			void display(){ INode::display(); cout << "DINode:" << node << endl; }
			DINode& operator = (DINode& rhs)
			{
				this->node = rhs.node;
				return *this;
			}
	private:
			int node;
};

int main()
{
	DINode a(1,2);
	//a.display();
	cout << "=================" << endl;
	DINode b = a;
	//b.display();
	return 0;
}
