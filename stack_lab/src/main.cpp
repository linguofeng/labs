#include <iostream>

class Stack {
    private:
        // 栈元素，由当前元素值与当前栈最小值构成
        class Item {
            public:
                Item() {
                    this->data = 0;
                    this->min = 0;
                }

                Item(int data) {
                    this->data = data;
                }

                ~Item() {
                    std::cout << "Stack::Item 析构了~\n";
                }

                void tostring(void) {
                    //std::cout << "{" << this->data << " ," << this->min << "}";
                    std::cout << this->data;
                }
            public:
                int data; // 当前元素的值
                int min;  // 当前栈中的最小值
        };

    public:
        Stack(): index(0) {
        }

        ~Stack() {
            for (int i = 0; i < index; ++i)
                delete items[i];

            std::cout << "Stack 析构了~\n";
        }

        int min(void) {
            if (this->topItem == NULL)
                return -1;
            return this->topItem->min;
        }

        void push(int data)
        {
            int len = sizeof(items) / sizeof(Item);
            if (index >= len) {
                std::cout << "栈已经满了\n";
                return;
            }

            Item* item = new Item(data);

            if (index == 0) {
                item->min = data;
            } else {
                // 如果data小于当前栈的最小值，则最小值为data
                if (data < this->topItem->min) {
                    item->min = data;
                } else {
                    item->min = this->topItem->min;
                }
            }

            this->items[index] = item;
            this->topItem = item;
          
            // 栈元素个数
            ++index;
        }

        // 出栈
        int pop(void)
        {
            if (index == 0) {
                std::cout << "栈已经空了\n";
                return -1;
            }

            // 出栈, 因为栈从0开始, 所以要减1
            --index;
            int data = items[index]->data;
            delete items[index];
            items[index] = NULL;

            // 重新修改栈顶的元素
            this->topItem = items[index - 1];

            return data;
        }

        void tostring(void) {
            if (index <= 0)
                return;

            std::cout << "{list:["; 
            items[0]->tostring();
            for (int i = 1; i < index; ++i) {
                std::cout << ", ";
                items[i]->tostring();
            }
            std::cout << "]}\n";
        }

    private:
        Item* items[10];
        Item* topItem;
        int index;
};

int main() {

    Stack* pStack = new Stack();

    pStack->push(32);
    pStack->push(12);
    pStack->push(54);
    pStack->push(87);
    pStack->push(1);
    pStack->pop();
    pStack->push(9);
    pStack->push(6);
    pStack->push(123);
    pStack->push(45);
    pStack->push(34);
    pStack->push(36);
    pStack->push(52);
    pStack->pop();

    pStack->tostring();
    std::cout << "最小值: " << pStack->min() << "\n";
    
    delete pStack;

    return 0;
}
