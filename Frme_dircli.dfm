object Frame_dircli: TFrame_dircli
  Left = 0
  Top = 0
  Width = 456
  Height = 181
  TabOrder = 0
  object lbl_dato: TLabel
    Left = 40
    Top = 8
    Width = 45
    Height = 13
    Alignment = taRightJustify
    Caption = 'Dirección'
  end
  object lbl_letras: TLabel
    Left = 56
    Top = 82
    Width = 29
    Height = 13
    Caption = 'Letras'
    Visible = False
  end
  object lbl_tipotarjeta: TLabel
    Left = 74
    Top = 106
    Width = 14
    Height = 13
    Caption = 'TC'
    Visible = False
  end
  object lbl_dato2: TLabel
    Left = 40
    Top = 32
    Width = 45
    Height = 13
    Alignment = taRightJustify
    Caption = 'Dirección'
    Visible = False
  end
  object lbl_dato3: TLabel
    Left = 40
    Top = 58
    Width = 45
    Height = 13
    Alignment = taRightJustify
    Caption = 'Dirección'
    Visible = False
  end
  object edt_dircli: TEdit
    Left = 93
    Top = 5
    Width = 164
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 25
    TabOrder = 0
  end
  object edt_dircli2: TEdit
    Left = 93
    Top = 29
    Width = 164
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 25
    TabOrder = 1
  end
  object lkcmb_poblac: TDBLookupComboBox
    Left = 93
    Top = 54
    Width = 267
    Height = 21
    KeyField = 'NOMBRE'
    ListSource = dts_poblac
    TabOrder = 2
    Visible = False
  end
  object edt_letras: TdxCurrencyEdit
    Left = 93
    Top = 78
    Width = 54
    TabOrder = 3
    TabStop = False
    Visible = False
    ReadOnly = True
    DisplayFormat = '0;-0'
    StoredValues = 64
  end
  object lkcmb_tipotarjeta: TDBLookupComboBox
    Left = 93
    Top = 102
    Width = 130
    Height = 21
    DropDownWidth = 200
    KeyField = 'clave'
    ListField = 'clave'
    ListSource = dts_tipotarjeta
    TabOrder = 4
    Visible = False
  end
  object dbgrd_poblacs: TdxDBGrid
    Left = 24
    Top = 118
    Width = 415
    Height = 41
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'TDA'
    SummaryGroups = <
      item
        DefaultGroup = False
        SummaryItems = <
          item
            ColumnName = 'dbgrd_renpolBonif'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_renpolRecar'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_renpolIMPOR'
            SummaryType = cstSum
          end
          item
            ColumnName = 'dbgrd_renpolNeto'
            SummaryType = cstSum
          end>
        Name = 'dbgrd_renpolSummaryGroup2'
      end>
    SummarySeparator = ', '
    TabOrder = 5
    Visible = False
    Filter.Criteria = {00000000}
    OptionsBehavior = [edgoAutoSearch, edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseLocate]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
  end
  object edt_codpost: TEdit
    Left = 245
    Top = 101
    Width = 164
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 25
    TabOrder = 7
    Visible = False
  end
  object edt_colonia: TEdit
    Left = 245
    Top = 77
    Width = 164
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 25
    TabOrder = 6
    Visible = False
  end
  object qry_poblac: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.nombre, a.numero, c.nombre as estado'
      'from poblacs a'
      'join car_relpobs b on a.numero = b.iddato1'
      'join car_estados c on b.iddato2 = c.idestado'
      'where b.tiporel = 2'
      'order by a.nombre'
      '')
    Left = 362
    Top = 18
  end
  object dts_poblac: TDataSource
    DataSet = qry_poblac
    Left = 332
    Top = 18
  end
  object dts_tipotarjeta: TDataSource
    DataSet = qry_tipotarjeta
    Left = 338
    Top = 46
  end
  object qry_tipotarjeta: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from car_termitarjetas'
      'where tipo = :TIPOTARJETA and cia = :CIA '
      'order by clave'
      ' ')
    Left = 365
    Top = 45
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPOTARJETA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_movto: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave, nombre from tallser where status = '#39'A'#39' ')
    Left = 364
    Top = 82
  end
  object dts_movto: TDataSource
    DataSet = qry_movto
    Left = 334
    Top = 82
  end
  object qry_lineas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Left = 394
    Top = 17
  end
  object dts_linea: TDataSource
    DataSet = qry_lineas
    Left = 427
    Top = 15
  end
  object qry_rutas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select dia,descri from rutas')
    Left = 395
    Top = 50
  end
  object dts_rutas: TDataSource
    DataSet = qry_rutas
    Left = 424
    Top = 80
  end
end
