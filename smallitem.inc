<?php	unset($islikes);unset($itemid);unset($wsubcat);unset($witems);unset($imgs);
				$itemid=$rows["$x"]["itemid"];
					$query="SELECT thumbpath FROM `images` WHERE `images`.`itemid`='{$rows[$x]["itemid"]}' LIMIT 1";
					$result = $mysqli->query($query);
						while($row = $result->fetch_array(MYSQLI_ASSOC)){
							$imgs=$row;
					}if (empty($imgs)){$imgs["thumbpath"]="/images/noimage.png";} ?>
					<div class="smallitem" style="position:relative; float:left; background-color: #f8f8f8; border:1px solid #fff;
						border-collapse:collapse; margin:0; max-width:280px; max-height:240px; overflow:hidden;">
						<div class="mdiv" tag="tag<?=$x?>" style="max-width:280px; max-height:180px; width:280px; height:180px;">
							<a class="item" href="item.php?lang=<?=$_SESSION['lang']?>&view=photos&item=<?=$rows["$x"]["itemid"]?>">
							<img src="<?=$imgs["thumbpath"]?>" alt="<?=$rows["$x"]["itemname"]?>" style="display:block; margin:auto; max-width:280px; width: auto; height: 210px; border:none;">
							</a>
						</div>
						<div style="position: relative; background:#f8f8f8; width:100%; max-width:280px; float:left; text-align:left; height: 50px; font-size:16px; padding-top:10px; margin-bottom:-60px;">
							<span style="padding-left:10px; max-width:265px; display:inline-block; white-space: nowrap; font-weight:bold; overflow:hidden;"><?=$rows["$x"]["itemname"]?>
							</span><br />
							<span style="font-size:14px; padding-left:10px;"><?=$rows["$x"]["username"]?></span>
							<span
							<?php if ($fgmembersite->CheckLogin()==true){echo 'class="'.$getget->getmatchmeter($rows["$x"]["itemid"], $_SESSION["name_of_user"]).'"';}?> style="position:absolute; top:0; right:0; display:block; height:59px; width:40px;">
							</span>
						</div>
						<div class="mdiv1" tag="tag<?=$x?>" style="float:left; position:relative; z-index:15; height:60px; padding:0; margin:0; width:50%;">
						</div>
						<div class="mdiv2" tag="tag<?=$x?>" style="float:left; position:relative; z-index:15; height:60px; padding:0; margin:0; width:50%;">
						</div>
					</div>
					<?php 
/*
Let's SWAP 
*/
?>
					<div class="letsswap" id="item<?=$rows["$x"]["itemid"]?>" style="display:none; float:left; width:280px; height:240px; padding:0; margin:1px 1px 1px -281px; z-index:250;">
						<form name="quickswap" action="index.php?confirmswap=<?=$rows["$x"]["itemid"]?>" method="post" enctype="multipart/form-data">
						<div style="position:relative; width:100%; height:150px; background: rgba(0, 0, 0, 0.8); padding-top:29px; text-align:center;">
							<input type="text" name="itemid" style="display:none;" value="<?=$rows["$x"]["itemid"]?>" />
							<select name="swapitem" style="width:240px; height:30px; margin-top:10px;">
							<option value="0"><?=$menuvoc["selectyouritem"][$_SESSION["lang"]]?></option>
							<?php
								foreach ($dbitems as $myitm){
								echo '<option value="'.$myitm['itemid'].'">'.$myitm['itemname'].'</option>';}
							?>
							</select>
							<select name="swapage" style="width:240px; height:30px; margin-top:10px;">
							<option selected="">--<?=$menuvoc["offervalid"][$_SESSION["lang"]]?>--</option>
							<option value="3">-- <?=$menuvoc["days3"][$_SESSION["lang"]]?> --</option>
							<option value="5">-- 5 <?=$menuvoc["days57"][$_SESSION["lang"]]?> --</option>
							<option value="7">-- 7 <?=$menuvoc["days57"][$_SESSION["lang"]]?> --</option>
							</select>
							<legend style="color:yellow; padding-top:5px; margin:0 0 -5px 10px;"><?=$menuvoc["additionalinfo"][$_SESSION["lang"]]?></legend>
							<input type="text" name="addinfo" value="" style="width:240px; height:20px; margin-top:10px;"/>
							<input type="button" value="<?=$menuvoc["close"][$_SESSION["lang"]]?>" class="closeletsswap" item="<?=$rows["$x"]["itemid"]?>" style="position:absolute; right:5px; top:5px; background-color:#c55; color:#fff; width:60px; height:22px; border:1px solid #bbb;" />
						</div>
						<div class="letsswapbtn" style="position:relative; width:280px; height:62px;">
							<div style="position:relative; width:100%; height:62px; z-index:250; background:#44ab7b; line-height:60px;">
								<button type="submit"
								style="display:block; background:#44ab7b; width:100%; height:100%; text-align:center; color:white; font-size:22px; border:none;">
								<span><?=$menuvoc["sendanoffer"][$_SESSION["lang"]]?></span></button>
							</div>
						</div>
						</form>
					</div>
<?php 
/*
SHOW HOVERS ON LOGIN ONLY
*/					
		if (!empty($_SESSION["name_of_user"]) and !isset($_GET["swap"])){ ?>
					<div class="divx" id="tag<?=$x?>" style="display:none; float:left; width:280px; height:180px; padding:0; margin:1px 1px 1px -281px;">
						<div id="divspanmain">
							<div style="height:40px;">
							
							<?php 
								$query="SELECT DISTINCT `id` FROM `follow` 
								WHERE 
								`follow`.`followedusr`='{$rows["$x"]["username"]}' 
								AND 
								`follow`.`username`='{$_SESSION['name_of_user']}'"; 
								$result=$mysqli->query($query);
								while($row = $result->fetch_array(MYSQLI_ASSOC)){
									$followed=$row;
								}
								if (!empty($followed))
								{?>
									<span id="hoverspanf" class="followed" todo="follow" username="<?=$_SESSION['name_of_user']?>" followedusr="<?=$rows["$x"]["username"]?>">
									<?php echo $menuvoc["canceluserfollow"][$_SESSION["lang"]];
								}
								else 
								{
									if (isset($_GET["follow"]))
									{?>
										<span id="hoverspanf" class="followed" todo="follow" username="<?=$_SESSION['name_of_user']?>" followedusr="<?=$rows["$x"]["username"]?>">
										<?php echo $menuvoc["canceluserfollow"][$_SESSION["lang"]];
									}
									else
									{?>
										<span id="hoverspanf" class="follow" todo="follow" username="<?=$_SESSION['name_of_user']?>" followedusr="<?=$rows["$x"]["username"]?>">
										<?php echo $menuvoc["userfollow"][$_SESSION["lang"]];
									}
								}
							unset($followed);?>
							</span>

							<?php
								$query="SELECT `id` FROM `likes` WHERE `likes`.`itemid`='{$rows["$x"]["itemid"]}' AND `likes`.`username`='{$_SESSION['name_of_user']}'"; 
								$result=$mysqli->query($query);
								while($row = $result->fetch_array(MYSQLI_ASSOC)){
									$islikes=$row;
								}
								if (!empty($islikes)){?>
									<span id="hoverspanb" class="basket" todo="basket" username="<?=$_SESSION['name_of_user']?>" itemid="<?=$rows[$x]["itemid"]?>" ><?=$menuvoc["frombasket"][$_SESSION["lang"]]?></span>
									<?php
								}else {
									if (isset($_GET["like"])){ ?>
									<span id="hoverspanb" class="basket" todo="basket" username="<?=$_SESSION['name_of_user']?>" itemid="<?=$rows[$x]["itemid"]?>"><?=$menuvoc["frombasket"][$_SESSION["lang"]]?></span>
									<?php }
									else{?>
								<span id="hoverspanb" class="like" todo="basket" username="<?=$_SESSION['name_of_user']?>" itemid="<?=$rows[$x]["itemid"]?>"><?=$menuvoc["tobasket"][$_SESSION["lang"]]?></span>
								<?php }}
							unset($islikes);?>
							<?php 
								$query="SELECT `dealid`,`wi_username` FROM `deals` 
								WHERE 
								`deals`.`wi_itemid`='{$rows["$x"]["itemid"]}' 
								AND 
								`deals`.`ofi_username`='{$_SESSION['name_of_user']}' AND status!='3'
								OR `deals`.`ofi_itemid` = '{$rows["$x"]["itemid"]}'
								AND `deals`.`wi_username` = '{$_SESSION['name_of_user']}' AND status!='3' LIMIT 1"; 
								$result=$mysqli->query($query);
								while($row = $result->fetch_array(MYSQLI_ASSOC)){
									$indeal=$row;
								}
								if (!empty($indeal)){?>
									<div id="hoverspanindeal" class="indeal"><a href="deal.php?dealid=<?=$indeal["dealid"]?>&view=offer&order=<?php 
									if($indeal["wi_username"]!=$_SESSION['name_of_user'])
									{ echo 'fromme'; } else { echo 'tome'; } ?>"><?=$menuvoc["watchdeal"][$_SESSION["lang"]]?></a></div>
								<?php
								}else{?>
									<span id="hoverspanindeal" class="notindeal letsswapbtn" item=<?=$rows["$x"]["itemid"]?>><?=$menuvoc["letsswap"][$_SESSION["lang"]]?></span>
								<?php }
							?>
							</div>
							<div style="height:20px;">
							<?php
								$query="SELECT id FROM follow WHERE followedusr='{$rows["$x"]["username"]}'";
								$result = $mysqli->query($query);
							?>	
							<span class="countfollowed" count="<?=$result->num_rows?>" username="<?=$_SESSION['name_of_user']?>" followedusr="<?=$rows["$x"]["username"]?>" style="float:right; color:#ff0; font-size:16px; margin-right:22px;">
							<?php echo $result->num_rows; ?>
								</span>
							<?php
								$query="SELECT id FROM likes WHERE itemid='{$rows["$x"]["itemid"]}'";
								$result = $mysqli->query($query);
							?>
							<span class="countbasket" count="<?=$result->num_rows?>" username="<?=$_SESSION['name_of_user']?>" itemid="<?=$rows["$x"]["itemid"]?>" style="float:right; color:#ff0; font-size:16px; margin-right:33px;">
							<?php
								echo $result->num_rows;
							?></span>
							<span style="float:right; color:#ff0; font-size:16px; margin-right:33px;">
							<?php
								$query="SELECT id FROM deals WHERE wi_itemid='{$rows["$x"]["itemid"]}'OR ofi_itemid='{$rows["$x"]["itemid"]}'";
								$result = $mysqli->query($query);
								echo $result->num_rows;
							?></span>
							</div>
						</div>
						<a href=item.php?lang=<?=$_SESSION['lang']?>&view=photos&item=<?=$rows["$x"]["itemid"]?>>
						<div style="position:relative;width:100%; height:110px; z-index:100;">
						</div>
						</a>
					</div>
					<div class="divx1" id="atag<?=$x?>" style="display:none; float:left; width:280px; height:180px; padding:0; margin:1px 1px 1px -281px; z-index=200;">
						<div id="divspanmain2">
							<div style="position:relative; width:100%; height:171px; background:#000;  padding-top:10px;">
							<?php
								$query="SELECT DISTINCT `image`,`country`,`city` FROM `users` WHERE `users`.`username`='{$rows["$x"]["username"]}'";
								$result = $mysqli->query($query);
								while($row = $result->fetch_array(MYSQLI_ASSOC)){
											$uimage=$row;
										}
								$query="SELECT `id` FROM `gallery` WHERE `gallery`.`username`='{$rows["$x"]["username"]}' AND `gallery`.`public`='1'";
								$result = $mysqli->query($query);
								$upublished=$result->num_rows;

								$query="SELECT `id` FROM `deals` WHERE `deals`.`wi_username`='{$rows["$x"]["username"]}' AND `deals`.`status`='2' OR `deals`.`ofi_username`='{$rows["$x"]["username"]}' AND `deals`.`status`='2'";
								$result = $mysqli->query($query);
								$upositive=$result->num_rows;
							?>
							<span style="color:white; padding-left:5px;"><?=$menuvoc["country"][$_SESSION["lang"]]?>: <?=$uimage["country"]?> / <?=$menuvoc["city"][$_SESSION["lang"]]?>: <?=$uimage["city"]?></span><br />
							<div style="float:left; margin:auto; width:140px; height:140px;padding-top:15px;">
								<a href="index.php">
								<img width="140" height="140" src="<?=$uimage["image"]?>" alt="<?=$rows["$x"]["username"]?>" />
								</a>
							</div>
							<div style="float:left; height:140px; width:120px; margin-left:10px; background:#000;">
								<?php 
									unset($userrating);unset($rating);
									$query="SELECT COUNT(CASE WHEN rating = '1' AND `username`='{$rows["$x"]["username"]}' THEN 1 ELSE NULL END) AS positive, COUNT(CASE WHEN `username`='{$rows["$x"]["username"]}' THEN 1 ELSE NULL END) AS total FROM rates_comments";
									$result = $mysqli->query($query);
									if(!empty($result)){
									while($row = $result->fetch_array(MYSQLI_ASSOC)){
										$rating[]=$row;}
										if($rating[0]['total']!=0){
										$userrating=round($rating[0]['positive']/$rating[0]['total']*100);
										}else $userrating=0;
									}
								?>
								<div style="position:relative; height:51px;text-align:center; line-height: 24px; border-bottom:1px solid #aaa; background-image:url('/images/icons/rate.png'); background-repeat:no-repeat; background-position:10px 2px;">
									<span style="position:absolute; color:#ff0; top:10px; left:55px; font-weight:bold; font-size:16px;">
										<?=$userrating?> %
									</span>
									<span style="position:absolute; top:30px; left:0px; color:#fff; font-weight:bold;">
										<?=$menuvoc["rating"][$_SESSION["lang"]]?>
									</span>
								</div>
								<div style="position:relative; height:51px;text-align:center; line-height: 24px; border-bottom:1px solid #aaa;background-image:url('/images/icons/items.png'); background-repeat:no-repeat; background-position:10px 2px;">
									<span style="position:absolute; color:#ff0; top:10px; left:65px; font-weight:bold; font-size:16px;">
										<?php echo $upublished; ?>
									</span>
									<span style="position:absolute; top:30px; left:0px; color:#fff; font-weight:bold;">
										<?=$menuvoc["published"][$_SESSION["lang"]]?>
									</span>
								</div>
								<div style="position:relative; height:44px;text-align:center; line-height: 24px;background-image:url('/images/icons/yesdeals.png'); background-repeat:no-repeat; background-position:10px 2px;">
									<span style="position:absolute; color:#ff0; top:10px; left:65px; font-weight:bold; font-size:16px;">
										<?php echo $upositive; ?>
									</span>
									<span style="position:absolute; top:30px; left:0px; color:#fff; font-weight:bold;">
										<?=$menuvoc["positivedeal"][$_SESSION["lang"]]?>
									</span>
								</div>
							</div>
							</div>
							<div class="usernfo" style="position:relative; z-index:12;  width:280px; height:60px; text-align:center;">
								<div style="float:left; width:140px; height:60px; background-color:#17365d; color:#fff; line-height:60px; font-size:16px;"><?=$menuvoc["userinfo"][$_SESSION["lang"]]?></div>
								<?php if(isset($indeal)){?>
									<div item=<?=$rows["$x"]["itemid"]?> style="position:relative; z-index:12; width:140px; float:right;height:60px; background:#21abad; line-height:60px;">
										<span style="display:block; width:100%; height:100%; text-align:center; color:white; font-size:16px;"><?=$menuvoc["watchdeal"][$_SESSION["lang"]]?></span>
									</div>
							<?php }else{ ?>
								<div style="position:relative; z-index:12; width:140px; float:right;height:60px; background:#44ab7b; line-height:60px;">
									<span style="display:block; width:100%; height:100%; text-align:center; color:white; font-size:16px;"><?=$menuvoc["letsswap"][$_SESSION["lang"]]?></span>
								</div>
							<?php }?>
							</div>
						</div>
					</div>
					<div class="divx2" id="btag<?=$x?>" style="display:none; float:left; width:280px; height:180px; padding:0; margin:1px 1px 1px -281px; z-index=200;">
						<div id="divspanmain2">
							<div class="divx2out" style="position:relative; width:100%; height:151px; background:#000; opacity:0.85; padding-top:30px;">
							<span style="line-height:30px; color:white; margin-left:10px;"><?=$menuvoc["wantedcategory"][$_SESSION["lang"]]?> / <?=$menuvoc["wantedsubcat"][$_SESSION["lang"]]?></span><br />
							<?php
							$query = "SELECT 
								wmodule,
								wcat,
								wsubcat
								FROM wantlist WHERE `wantlist`.`itemid`='$itemid'";
							$result = $mysqli->query($query);
							while($row = $result->fetch_array(MYSQLI_ASSOC)){
								$witems[]=$row;
							}
							if (!empty($witems)){
							foreach ($witems as $wanted){
								echo '<div style="text-align:left;margin-left:10px;">
								<span style="color:#ff0;">'.$catalog[$wanted["wmodule"]][$_SESSION["lang"]].' /</span>
								<span style="color:#ff0;">'.$catalog[$wanted["wmodule"]][$wanted["wcat"]][$_SESSION["lang"]].' /</span>
								<span style="color:#ff0;">'.$catalog[$wanted["wmodule"]][$wanted["wcat"]][$wanted["wsubcat"]][$_SESSION["lang"]].'</span><br /></div>';
							}}
							?>
							</div>
							<?php if(isset($indeal)){?>
							<div class="" style="position:relative; width:280px; height:60px; text-align:center;">
								<div style="float:left; width:140px; height:60px; background-color:#17365d; z-index:12; color:#fff; line-height:60px; font-size:16px;"><?=$menuvoc["userinfo"][$_SESSION["lang"]]?></div>
								<a href="deal.php?dealid=<?=$indeal["dealid"]?>&view=offer&order=fromme">
									<div class="mdiv2" item=<?=$rows["$x"]["itemid"]?> style="position:relative; z-index:16; width:140px; float:right;height:60px; background:#21abad; line-height:60px;">
										<span style="display:block; width:100%; height:100%; text-align:center; color:white; font-size:16px;"><?=$menuvoc["watchdeal"][$_SESSION["lang"]]?></span>
									</div>
								</a>
							</div>
							<?php }else{ ?>
							<div style="position:relative; width:280px; height:60px; text-align:center;">
								<div style="float:left; width:140px; height:60px; background-color:#17365d; color:#fff;  z-index:12; line-height:60px; font-size:16px;"><?=$menuvoc["userinfo"][$_SESSION["lang"]]?></div>
								<div class="mdiv2 letsswapbtn" item=<?=$rows["$x"]["itemid"]?> style="position:relative; z-index:16; width:140px; float:right;height:60px; background:#44ab7b; line-height:60px;">
									<span style="display:block; width:100%; height:100%; text-align:center; color:white; font-size:16px;"><?=$menuvoc["letsswap"][$_SESSION["lang"]]?></span>
								</div>
							</div>
							<?php } ?>
						</div>
					</div>
					<?php unset($islikes);unset($itemid);unset($wsubcat);unset($witems);unset($imgs);unset($indeal);
					}
?>