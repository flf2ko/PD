<?php

	session_start() ;
	$db_host = 'localhost' ;
	$db_database = 'pd course' ;
	$db_username = 'root' ;
	$connection = mysql_connect($db_host, $db_username, '');
	if (!$connection)
		die ("connection failed".mysql_error()) ;
	mysql_query("SET NAMES 'utf8'");
	$selection = mysql_select_db($db_database) ;
	if (!$selection)
		die ("selection failed".mysql_error()) ;
	
	date_default_timezone_set('Asia/Taipei');
	$datetime = date ("Y/m/d H:i:s");
	echo $datetime.'<br>';
	
	if (!$_SESSION['account']){            // �ϥΪ̥��n�J�A�ɦ^login.php
		header ("Location:login.php") ;
	} else if (isset($_POST['textarea'])){ // �ϥ�textarea�W��
		echo "Hello, ".$_SESSION['account']."<br>";
		echo 'textarea'.$_POST['textarea'] ;
	}
	else  if (isset($_FILES['upload'])){   // ����ɮפW��
		$problem_dir = '.\\student\\'.$_SESSION['account'].'\\'.$_POST['problem_num']; 
		if (!is_dir($problem_dir)){
			$return = 0;
			$command = "MD ".$problem_dir;
			system($command, $return);
		}
		$judge_dir = '.\\judgement\\'.$_POST['problem_num'];
		$upfile = $problem_dir.'\\hw.cpp';
		$exefile = $problem_dir.'\\hw.exe';
		$compile_logfile = $problem_dir.'\\compile_err_log.txt';
		$run_logfile = $problem_dir.'\\run_err_log.txt';
		$testfile = $judge_dir.'\\testing_data.txt';
		$outputfile = $problem_dir.'\\output.txt';
		move_uploaded_file($_FILES['upload']['tmp_name'], $upfile);
		
		// if (!file_exists($logfile)){
			// $fp = fopen($logfile, 'w');
			// fclose($fp);
		// }
	
		$return = 1;
		
		//�sĶ.cpp��
		//$command = 'g++ '.$upfile.' -o '.$exefile.' -enable-auto-import 2> '.$logfile;
		$command = 'g++ '.$upfile.' -o '.$exefile.' 2> '.$compile_logfile;
		system($command,$return);
		
		//�p�G���\�sĶ�X.exe�� ����.exe ��J���ꬰ$testfile �зǿ�X��V��$outputfile �зǿ��~��V��$run_logfile
		if (file_exists($exefile)){
			$command = $exefile.' < '.$testfile.' > '.$outputfile.' 2> '.$run_logfile;
			system($command,$return);
		} else {
			//compile error
		}
		
		$command = 'python judge.py '.$_SESSION['account'].' '.$_POST['problem_num'];
		system($command,$return);
		
		echo "Hello, ".$_SESSION['account']."<br>";
		echo 'file upload success';
	}
	else if (!isset($_FILES['upload']) and !isset($_POST['textarea'])){
		echo 'no upload';
	}

?>