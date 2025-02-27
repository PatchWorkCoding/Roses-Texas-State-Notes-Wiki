#include <iostream>
#include <cassert>
#include <stack>

std::stack<int> towerA, towerB, towerC;

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
	void moveTowerImpl(int n, char src_tower_id, char dst_tower_id, char spare_tower_id)
	{
		// Check to see if there are any more disks in the stack to move
		// If not print the instruction and return early.
		if (n == 1)
		{
			int disc_Value = -1;
			switch (src_tower_id)
			{
				case 'A':
					disc_Value = towerA.top();
					towerA.pop();
					break;
				case 'B':
					disc_Value = towerB.top();
					towerB.pop();
					break;
				case 'C':
					disc_Value = towerC.top();
					towerC.pop();
					break;
			}
			switch (dst_tower_id)
			{
				case 'A':
					towerA.push(disc_Value);
					break;
				case 'B':
					towerB.push(disc_Value);
					break;
				case 'C':
					towerC.push(disc_Value);
					break;
			}
			//std::cout << "move disk " << n - 1 << " from " << src_tower_id << " to " << dst_tower_id << std::endl;
			return;
		}

		// Otherwise:
		// Move all the disks above this one to the spare tower
		moveTowerImpl(n - 1, src_tower_id, spare_tower_id, dst_tower_id);

		int disc_Value = -1;
			switch (src_tower_id)
			{
				case 'A':
					disc_Value = towerA.top();
					towerA.pop();
					break;
				case 'B':
					disc_Value = towerB.top();
					towerB.pop();
					break;
				case 'C':
					disc_Value = towerC.top();
					towerC.pop();
					break;
			}
			switch (dst_tower_id)
			{
				case 'A':
					towerA.push(disc_Value);
					break;
				case 'B':
					towerB.push(disc_Value);
					break;
				case 'C':
					towerC.push(disc_Value);
					break;
			}
		// Move this disk to the destination tower
		//std::cout << "move disk " << n - 1 << " from " << src_tower_id << " to " << dst_tower_id << std::endl;

		// Move all the disks that we put on the spare tower back on top of this disk on the destination tower
		moveTowerImpl(n - 1, spare_tower_id, dst_tower_id, src_tower_id);
	
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
	for (int i = disk_num - 1; i >= 0; i--)
	{
		towerA.push(i);
	}
	
	//Throws an error if there are 0 or less disks to move
	if (disk_num <= 0) {
		throw std::invalid_argument("Disk number must be greater than zero");
	}

	//Otherwise call the recursive function
	moveTowerImpl(disk_num, 'A', 'B', 'C');

	//std::cout << towerB.empty();
	int counter = disk_num;
	while (!towerB.empty())
	{
		towerB.pop();
		counter--;
	}

	if (counter == 0 && towerA.empty() && towerB.empty() && towerC.empty())
	{
		std::cout << disk_num << " succeeded!" << std::endl;
	}
	else
	{
		std::cout << disk_num << " failed." << std::endl;
	}
	
	
	
}


int main() {
	std::cout << "Please enter the number of disk initially on Tower A: ";

	int n;
	std::cin >> n;
	
	for (int i = 1; i < 100; i++)
	{
		moveTower(i);
	}

	return 0;
}

