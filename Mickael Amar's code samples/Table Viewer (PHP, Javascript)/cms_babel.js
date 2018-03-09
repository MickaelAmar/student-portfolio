(function()
{
  var select = $("#table-names-select");
  var currentDatatable = undefined;

  function onChange()
  {
    var tableName = select.val();

    $.get('php/table_viewer_process.php', {action: 'load_column_names', table: tableName}, function(columnsName)
    {
      var names = [];

      for (var i = 0; i < columnsName.length; i++)
      {
        names.push(columnsName[i]['Field']);
      }
      removeDatatable('#example1', currentDatatable);
      currentDatatable = newDatatable('example1', names, [], {
        "processing": true,
        "serverSide": true,
        "ajax": {
          "url": "php/table_viewer_processing.php",
          "type": "POST",
          "data": function(d)
          {
            d.table = tableName;
            d.columnsName = names;
          }
        },
        "drawCallback": function()
        {
          $('#example1 tr').click(function()
          {
            var data = $('#example1').DataTable().row(this).data();
            var columnsValue = {
              tableName: tableName,
              columns: {}
            };
            for (var i = 0; i < columnsName.length; i++)
            {
              columnsValue.columns[columnsName[i]['Field']] = {
                infos: columnsName[i],
                value: data[i]
              };
            }
            generateFullPanel(columnsValue);
          });
        },
        "scrollX": true,
        "pagingType": "simple",
        "language": {
          "lengthMenu": "Voir _MENU_ entrées",
          "searchPlaceholder": "Recherche",
          "search": "_INPUT_",
          "infoFiltered": "",
          "info": "_START_-_END_ sur _TOTAL_",
          "dom": 'fipBtr',
          "paginate": {
              "previous": "<b><</b>",
              "next": "<b>></b>"
          },
         }
      });
      $("#datatable").css("width","100%");
      $(".dt-buttons").css('float','');
      $("#example1_filter").css('text-align','left');

    }, 'json');
  }

  $.get('php/table_viewer_process.php', {action: 'load_table_names'}, function(tablesName)
  {
    var txt;

    for (var i = 0; i < tablesName.length; i++)
      {
        txt = escape(tablesName[i]['TABLE_NAME']);
        select.append("<option value='"+ txt +"'>"+ txt +"</option>");
      }
    select.trigger("change");
    select.change(onChange);

  }, 'json');
})();
