/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode track = l1;
        //System.out.println(track.val);
        ListNode track2 = l2;
        //System.out.println(track2.val);
        ListNode trackres = result;
        //System.out.println(result.next == null);
        int carry = 0;
                while (track != null && track2 != null) {
            if (track.val + track2.val + carry >= 10) {
                trackres.val = (track.val + track2.val + carry) %10;
                carry = 1;
            } else {
                trackres.val = track.val + track2.val + carry;   
                carry = 0;
            }
            //System.out.println(trackres.val);
            if ((track.next != null || track2.next!= null) && carry == 0) {
                trackres.next = new ListNode(0);   
            } else if (carry == 1) {
                trackres.next = new ListNode(1);   
            }
            track = track.next;
            //System.out.println(track.val);
            track2 = track2.next;
            //System.out.println(track2.val);
            trackres = trackres.next;          
        }
                while (track!= null) {
            if (trackres.val + track.val == 10) {
                trackres.val = 0;
                trackres.next = new ListNode(1);
                track = track.next;
                trackres = trackres.next;
            } else {
                trackres.val = trackres.val + track.val;
                track = track.next;
                if (track!=null) trackres.next = new ListNode(0);
                trackres = trackres.next;
            }
        }
                while (track2!= null) {
            if (trackres.val + track2.val == 10) {
                trackres.val = 0;
                trackres.next = new ListNode(1);
                track2 = track2.next;
                trackres = trackres.next;
            } else {
                trackres.val = trackres.val + track2.val;
                track2 = track2.next;
                if (track2!=null) trackres.next = new ListNode(0);
                trackres = trackres.next;
            }
        }
                        return result;
            }
}