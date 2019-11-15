<?php

	$client = array(
		'PT Vokasi',
		'Sekip UGM',
		'Yogyakarta'
	);

	$purchase = array(
		array('123','Blackberry Z10',1,4500000),
		array('234','LG Monitor 19 Inch',2,1500000),
		array('345','Epson EB-X11',1,4600000)
	);

	$discount = array ('10');

?>

<html>
<head></head>
<body>
	Prepared for : <b><?php echo implode(',',$client); ?></b><br>
	Date : <?php echo date('d M y'); ?>

	<br><br>

	<table border="1">
		<tr>
			<td>PLU</td>
			<td>Product Name</td>
			<td>Qty</td>
			<td>Price</td>
			<td>Total</td>
		</tr>

		<?php foreach($purchase as $purchase): ?>
			<tr>
				<?php for($i = 0; $i<count($purchase); $i++){ ?>
					<?php if($i==2 && $purchase[2]>1){ ?>
						<td style="background-color:yellow;">
					<?php } else { ?>
						<td>
					<?php } ?>
						<?php echo $purchase[$i]; ?>
					</td>
						<?php
							if($i==3){
								$quantity = $purchase[$i];
							} else {
								$total = $purchase[$i];
							}
						?>
				<?php } ?>
				<td><?php echo $quantity*$total; ?></td>
			</tr>
		<?php endforeach; ?>
	</table>
</body>
</html>