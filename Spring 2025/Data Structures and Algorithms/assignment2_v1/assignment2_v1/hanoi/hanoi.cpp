#include <iostream>
#include <cassert>


/*
 * Print the list of actions that move a set of disks on the top of a tower to another tower in the Tower of Hanoi.
 * This is the implementation of moveTower().
 *
 *   n              - the number of disks that will be moved from the top of the source tower to the destination tower
 *   src_tower_id   - the id of the source tower, which can only be either 'A', 'B', or 'C'.
 *   dst_tower_id   - the id of the destination tower, which can only be either 'A', 'B', or 'C'.
 *                    precondition: src_tower_id != dst_tower_id
 *   spare_tower_id - the id of the remaining tower, which can only be either 'A', 'B', or 'C'.
 *                    precondition: spare_tower_id != src_tower_id and spare_tower_id != dst_tower_id
 *
 * Output:
 *   Print the list of actions that move a set of n disks on the top of the tower src_tower_id to the tower dst_tower_id.
 */
void moveTowerImpl(int n, char src_tower_id, char dst_tower_id, char spare_tower_id)  {
	// TODO
}


/*
 * Print the list of actions that move a set of disks on Tower A to Tower B in the Tower of Hanoi.
 *
 *   disk_num - the number of disks on Tower A
 *
 * Output:
 *   Print the list of actions that move the disks on Tower A to Tower B
 *   Throw the std::invalid_argument exception if disk_num is less than or equal to zero.
 */
void moveTower(int disk_num) {
	if (disk_num <= 0) {
		throw std::invalid_argument("Disk number must be greater than zero");
	}
	moveTowerImpl(disk_num, 'A', 'B', 'C');
}


int main() {
	std::cout << "Please enter the number of disk initially on Tower A: ";

	int n;
	std::cin >> n;
	
	moveTower(n);

	return 0;
}

