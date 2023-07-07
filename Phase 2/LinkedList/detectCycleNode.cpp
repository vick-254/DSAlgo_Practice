

class ListNode
{
    int val;
    ListNode *next;

private:
    int lengthCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        int count = 0;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                ListNode *temp = slow;

                do
                {
                    temp = temp->next;
                    count++;
                } while (temp != slow);

                break;
            }
        }
        return count;
    }

public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *temp1 = head;
        ListNode *temp2 = head;
        int length = 0;

        ListNode *slow = head;
        ListNode *fast = head;

        while (slow && fast && fast->next)
        {

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                length = lengthCycle(slow);

                break;
            }
        }

        if (length == 0)
        {
            return nullptr;
        }

        while (length > 0)
        {
            temp1 = temp1->next;
            length--;
        }

        while (temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    }
};
