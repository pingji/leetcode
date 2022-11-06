impl Solution {
    pub fn find_number_in2_d_array(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if matrix.len() == 0 {
            return false
        }
        let mut i = 0;
        let mut j = matrix[0].len() as i32 - 1;
        while i < matrix.len() && j >= 0 {
            if matrix[i][j as usize] > target {
                j -= 1;
            } else if matrix[i][j as usize] < target {
                i += 1;
            } else {
                return true;
            }
        }
        false
    }
}