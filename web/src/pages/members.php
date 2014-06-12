
<ul class='list-group'>

	<?php
	require("inc/database.inc.php");
	$query = "SELECT u.nickname AS nickname , ug.`name` AS job FROM `user` AS u INNER JOIN usergroup AS ug ON u.usergroup = ug.id;";
	if($result = $dbConnection->query($query)){
		while($row = $result->fetch_assoc()){
			PrintMember($row["nickname"], $row["job"]);
		}
		$result->free();
	}
	
	function PrintMember($name, $job){
		$randMessages = rand(0,50);
		echo "<li class='list-group-item'>
			<div class='row'>
				<div class='col-md-2' >
					<img data-src='js/holder.js/42x42' alt='...'>
				</div>
				<div class='col-md-10' >
					<div class='row'>
						 <div class='col-md-5' > <a href'#'><span class='glyphicon glyphicon-user'></span> $name</a></div>
						 <div class='col-md-5' > <a href'#'><span class='glyphicon glyphicon-envelope'></span> Message </a><span class='badge'>$randMessages</span></div>
						 <div class='col-md-2' > <a href'#'> </a></div>
					</div>
					<a href'#'><span class='glyphicon glyphicon-briefcase'></span> $job</a>
					
				</div>
			</div>
		</li> ";
	
	}

	
	?>
    
</ul>

