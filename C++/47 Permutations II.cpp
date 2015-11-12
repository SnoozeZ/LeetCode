//Backtracking, adopt a map to eliminate the duplicate situation.
public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        LinkedList<Integer> list = new LinkedList<Integer>();
        for (int num : nums) list.add(num);
        permute(list, 0, res);
        return res;
    }
    private void permute(LinkedList<Integer> nums, int start, List<List<Integer>> res){
        if (start == nums.size() - 1){
            res.add(new LinkedList<Integer>(nums));
            return;
        }
        for (int i = start; i < nums.size(); i++){
            if (i > start && nums.get(i) == nums.get(i - 1)) continue;
            nums.add(start, nums.get(i));
            nums.remove(i + 1);
            permute(nums, start + 1, res);
            nums.add(i + 1, nums.get(start));
            nums.remove(start);
        }
    }
}
