object dlg_datosrenagenda: Tdlg_datosrenagenda
  Left = 326
  Top = 241
  Width = 589
  Height = 284
  Caption = 'Datos de la Entrega'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 205
    Width = 573
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object BitBtn1: TBitBtn
      Left = 169
      Top = 8
      Width = 75
      Height = 25
      Caption = 'OK'
      ModalResult = 1
      TabOrder = 0
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
    end
    object BitBtn2: TBitBtn
      Left = 273
      Top = 8
      Width = 75
      Height = 25
      TabOrder = 1
      Kind = bkCancel
    end
  end
  object pnl_datosentrega: TPanel
    Left = 0
    Top = 0
    Width = 573
    Height = 145
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label2: TLabel
      Left = 19
      Top = 48
      Width = 31
      Height = 13
      Caption = 'Chofer'
    end
    object Label5: TLabel
      Left = 291
      Top = 48
      Width = 35
      Height = 13
      Caption = 'Pto.Vta'
    end
    object Label6: TLabel
      Left = 5
      Top = 72
      Width = 47
      Height = 13
      Caption = 'Población'
    end
    object Label1: TLabel
      Left = 19
      Top = 118
      Width = 33
      Height = 13
      Caption = 'Código'
    end
    object Label4: TLabel
      Left = 291
      Top = 70
      Width = 35
      Height = 13
      Caption = 'Colonia'
    end
    object Observs: TLabel
      Left = 8
      Top = 96
      Width = 39
      Height = 13
      Caption = 'Observs'
    end
    object Label7: TLabel
      Left = 18
      Top = 23
      Width = 30
      Height = 13
      Caption = 'Fecha'
    end
    object Label8: TLabel
      Left = 295
      Top = 24
      Width = 28
      Height = 13
      Caption = 'Ubica'
    end
    object lkcmb_chofer: TDBLookupComboBox
      Left = 56
      Top = 43
      Width = 60
      Height = 21
      KeyField = 'CLAVE'
      ListField = 'CLAVE'
      ListSource = dts_promotor
      TabOrder = 2
    end
    object DBEdit2: TDBEdit
      Left = 118
      Top = 42
      Width = 162
      Height = 21
      TabStop = False
      DataField = 'NOMBRE'
      DataSource = dts_promotor
      TabOrder = 10
    end
    object DBEdit3: TDBEdit
      Left = 396
      Top = 42
      Width = 166
      Height = 21
      TabStop = False
      DataField = 'NOMBRE'
      DataSource = dts_ptovta
      TabOrder = 11
    end
    object lkcmb_ptovta: TDBLookupComboBox
      Left = 333
      Top = 43
      Width = 60
      Height = 21
      KeyField = 'CLAVE'
      ListField = 'CLAVE'
      ListSource = dts_ptovta
      TabOrder = 3
    end
    object lkcmb_poblac: TDBLookupComboBox
      Left = 56
      Top = 67
      Width = 225
      Height = 21
      KeyField = 'NOMBRE'
      ListField = 'NOMBRE'
      ListSource = dts_poblacs
      TabOrder = 4
    end
    object edt_codigo: TEdit
      Left = 56
      Top = 115
      Width = 121
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 13
      TabOrder = 7
      OnKeyDown = edt_codigoKeyDown
    end
    object edt_descri: TEdit
      Left = 180
      Top = 115
      Width = 230
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 8
    end
    object edt_colonia: TEdit
      Left = 332
      Top = 67
      Width = 230
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 30
      TabOrder = 5
    end
    object edt_observs: TEdit
      Left = 56
      Top = 91
      Width = 506
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 6
    end
    object date_fecha: TDateTimePicker
      Left = 55
      Top = 19
      Width = 90
      Height = 21
      CalAlignment = dtaLeft
      Date = 39686.4218035648
      Time = 39686.4218035648
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 0
    end
    object lkcmb_ubica: TDBLookupComboBox
      Left = 333
      Top = 19
      Width = 60
      Height = 21
      KeyField = 'UBICA'
      ListField = 'UBICA'
      ListSource = dts_almacen
      TabOrder = 1
    end
    object DBEdit1: TDBEdit
      Left = 396
      Top = 18
      Width = 166
      Height = 21
      TabStop = False
      DataField = 'DESCRI'
      DataSource = dts_almacen
      TabOrder = 12
    end
    object BitBtn3: TBitBtn
      Left = 424
      Top = 115
      Width = 75
      Height = 25
      Action = agrega_ren
      Caption = 'Agregar'
      TabOrder = 9
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
        FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF000000
        FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
        FF000000FF000000FF000000FF000000FF000000FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
        0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
        0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
        0000FF000000FF00FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
    end
  end
  object dbgrd_inven: TdxDBGrid
    Left = 0
    Top = 145
    Width = 573
    Height = 60
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'IDRENAGENDAART'
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    TabOrder = 2
    OnKeyDown = dbgrd_invenKeyDown
    DataSource = dts_renagendaart
    Filter.Active = True
    Filter.AutoDataSetFilter = True
    Filter.Criteria = {00000000}
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseLocate]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    object dbgrd_invenCODIGO: TdxDBGridMaskColumn
      Caption = 'Código'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODIGO'
    end
    object dbgrd_invenDESCRI: TdxDBGridMaskColumn
      Caption = 'Descripción'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DESCRI'
    end
  end
  object qry_ptovta: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, nombre from almacen where cia = :CIA order by clav' +
        'e')
    Left = 432
    Top = 75
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_ptovta: TDataSource
    DataSet = qry_ptovta
    Left = 464
    Top = 67
  end
  object qry_chofer: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, nombre  from promotor where tienda = '#39' 0'#39' order by' +
        ' clave')
    Left = 496
    Top = 75
  end
  object dts_promotor: TDataSource
    DataSet = qry_chofer
    Left = 528
    Top = 83
  end
  object dts_poblacs: TDataSource
    DataSet = qry_poblacs
    Left = 400
    Top = 67
  end
  object qry_poblacs: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select nombre, numero from poblacs order by nombre')
    Left = 368
    Top = 83
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select codigo, descri from inven where codigo = :CODIGO and cia ' +
        '= :CIA')
    Left = 32
    Top = 91
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_inven: TDataSource
    DataSet = qry_inven
    Left = 64
    Top = 83
  end
  object qry_almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select ubica, descri from inv_ubiptovta where cia = :CIA order b' +
        'y ubica')
    Left = 399
    Top = 137
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_almacen: TDataSource
    DataSet = qry_almacen
    Left = 431
    Top = 137
  end
  object qry_renagendaart: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select '
      'idrenagendaart, idrenagenda, idagenda, idcodigo, iddescri, cia,'
      'cast(b.concepto as varchar(13) ) as codigo, '
      'c.concepto as descri'
      'from inv_renagendaart a'
      'join conceps b on a.idcodigo = b.ncon'
      'join conceps c on a.iddescri = c.ncon'
      'where idrenagenda = :IDRENAGENDA')
    UpdateObject = uqry_renagendaart
    Left = 96
    Top = 83
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDRENAGENDA'
        ParamType = ptUnknown
      end>
  end
  object dts_renagendaart: TDataSource
    DataSet = qry_renagendaart
    Left = 128
    Top = 83
  end
  object uqry_renagendaart: TUpdateSQL
    Left = 167
    Top = 83
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 336
    Top = 176
    object agrega_ren: TAction
      Caption = 'Agregar'
      ImageIndex = 13
      OnExecute = agrega_renExecute
    end
    object borra_articulo: TAction
      Caption = 'Eliminar'
      ImageIndex = 17
      OnExecute = borra_articuloExecute
    end
  end
end
