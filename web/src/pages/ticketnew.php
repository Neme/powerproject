<script src='js/ckeditor/ckeditor.js'> </script>
<script type='text/javascript' src='js/moment.min.js'></script>
<script src='js/bootstrap-datetimepicker.min.js'></script>
<link rel='stylesheet' href='css/bootstrap-datetimepicker.min.css'>

<script src='js/bootstrap-slider.js'></script>
<link rel='stylesheet' href='css/slider.css'>

<?php 

function addDatePicker($id){
	echo "

	<div class='form-group'>
		<div class='input-group date' id='$id'>
			<input type='text' class='form-control' />
			<span class='input-group-addon'><span class='glyphicon glyphicon-calendar'></span>
			</span>
		</div>
	</div>

	
	<script>
		$(function () {
			$('#$id').datetimepicker({
				language: 'de'
			});
		});
	</script>";
}

function addSlider($id){
	echo "
	<div id='$id' class='slider slider-horizontal' data-slider-max='100' data-slider-value='0'>
	</div>

	
	<script>
		$('#$id').slider();
	</script>";
}
?>


<button class="btn btn-primary" data-toggle="modal" data-target=".bs-example-modal-lg">Ticket erstellen</button>
<br/><br/>
<div class="modal fade bs-example-modal-lg" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">   
        <div class='panel panel-default'>
            <div class='panel-heading'>Ticket erstellen</div>
            <div class='panel-body'>
                <form method='post'>
                    <div class='well'>
                        <div class='row'>
                            <div class='col-md-1'><p>Name</p></div>
                            <div class='col-md-4'><input class='form-control' type='text'></div>
                            <div class='col-md-1'><p>Zielgruppe</p></div>
                                                
                            <div class='col-md-4'>  
                                <div class='input-group'>
                                    <div class='input-group-btn'>
                                    <button type='button' class='btn btn-default dropdown-toggle' data-toggle='dropdown'>Alle <span class='caret'></span></button>
                                    <ul class='dropdown-menu'>
                                        <li><a href='#'>Programmierer</a></li>
                                        <li><a href='#'>Desinger</a></li>
                                        <li><a href='#'>Management</a></li>
                                        <li class='divider'></li>
                                        <li><a href='#'>Daniel</a></li>
                                        <li><a href='#'>Alex</a></li>
                                        <li><a href='#'>Rudi</a></li>
                                        <li><a href='#'>Jon</a></li>
                                        <li><a href='#'>Ella</a></li>
                                    </ul>
                                    </div>
                                    <input type='text' class='form-control'>
                                </div>
                            </div>
                            
                        </div>
                        <br/>
                        <p>Beschreibung</p>
                        <textarea id='descedit' name='editor1'></textarea>
                        <script type='text/javascript'>
                            CKEDITOR.replace( 'descedit' );
                        </script>
                    </div>
                    <div class='well'>
                    
                        <div class='row'>
                            <div class='col-md-1'><p>Startzeit</p></div>
                            <div class='col-md-4'><?php addDatePicker('datetimepickerStart'); ?></div>
                        </div>  
                        <div class='row'>  
                            <div class='col-md-1'><p>Abgabezeit</p></div>
                            <div class='col-md-4'><?php addDatePicker('datetimepickerEnd'); ?></div>
                        </div>
                        <div class='row'>  
                            <div class='col-md-1'><p>Erleding in %</p></div>
                            <div class='col-md-4'><?php addSlider('workDoneProgress'); ?></div>
                            <div class='col-md-1'><p>Aufwand (Studnen)</p></div>
                            <div class='col-md-3'><input class='form-control' type='number'></div>
                        </div>
                    </div>
                    <div class='well'>
                        <div class='row'>
                            <div class='col-md-1'><p>Priorität</p></div>
                            <div class='col-md-2'>
                                <div class='btn-group'>
                                    <button type='button' class='btn btn-default'>Niedrig</button>
                                    <button type='button' class='btn btn-default dropdown-toggle' data-toggle='dropdown'>
                                    <span class='caret'> </span>
                                    </button>
                                    <ul class='dropdown-menu' role='menu'>
                                        <li><a href='#'>Niedrig</a></li>
                                        <li><a href='#'>Mittel</a></li>
                                        <li><a href='#'>Hoch</a></li>
                                        <li><a href='#'>Sehr hoch</a></li>
                                    </ul>
                                </div>
                            </div>
                            <div class='col-md-1'><p>Status</p></div>
                            <div class='col-md-2'>
                                <div class='btn-group'>
                                    <button type='button' class='btn btn-default'>In Arbeit</button>
                                    <button type='button' class='btn btn-default dropdown-toggle' data-toggle='dropdown'>
                                    <span class='caret'> </span>
                                    </button>
                                    <ul class='dropdown-menu' role='menu'>
                                        <li><a href='#'>1. In Arbeit</a></li>
                                        <li><a href='#'>2. Test notwendig</a></li>
                                        <li><a href='#'>3. Feedback</a></li>
                                        <li><a href='#'>4. Fertig</a></li>
                                        <li class='divider'></li>
                                        <li><a href='#'>Geschlossen</a></li>
                                        <li><a href='#'>Frozen</a></li>
                                    </ul>
                                </div>
                            </div>
                        </div>  
                    </div>
                    <div class='well'>
                        <button type="button" class="btn btn-primary">Ticket erstellen</button>
                        <button type="button" class="btn btn-default">Schließen</button>
                    </div>
                </form>
        
            </div>
        </div>
    </div>
  </div>
</div>