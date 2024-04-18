object Frame_datosrenpolcobma: TFrame_datosrenpolcobma
  Left = 0
  Top = 0
  Width = 590
  Height = 194
  TabOrder = 0
  object Label1: TLabel
    Left = 16
    Top = 9
    Width = 45
    Height = 13
    Caption = 'Mayorista'
  end
  object Label2: TLabel
    Left = 16
    Top = 33
    Width = 36
    Height = 13
    Caption = 'Factura'
  end
  object Label3: TLabel
    Left = 24
    Top = 57
    Width = 24
    Height = 13
    Caption = 'Letra'
  end
  object Label4: TLabel
    Left = 15
    Top = 81
    Width = 49
    Height = 13
    Caption = 'Tipo Pago'
  end
  object Label5: TLabel
    Left = 168
    Top = 105
    Width = 46
    Height = 13
    Caption = 'Concepto'
  end
  object Label6: TLabel
    Left = 24
    Top = 105
    Width = 35
    Height = 13
    Caption = 'Importe'
  end
  object Label7: TLabel
    Left = 360
    Top = 35
    Width = 35
    Height = 13
    Caption = 'Importe'
  end
  object Label9: TLabel
    Left = 178
    Top = 59
    Width = 30
    Height = 13
    Caption = 'Fecha'
  end
  object Label8: TLabel
    Left = 360
    Top = 59
    Width = 27
    Height = 13
    Caption = 'Saldo'
  end
  object Label10: TLabel
    Left = 178
    Top = 81
    Width = 31
    Height = 13
    Caption = 'Vence'
  end
  object Label11: TLabel
    Left = 345
    Top = 81
    Width = 52
    Height = 13
    Caption = 'Referencia'
  end
  object lkcmb_mayoris: TDBLookupComboBox
    Left = 69
    Top = 7
    Width = 90
    Height = 21
    DropDownWidth = 200
    KeyField = 'codigo'
    ListField = 'codigo; NOMBRE'
    ListSource = dts_mayoris
    TabOrder = 0
    OnEnter = lkcmb_mayorisEnter
    OnExit = lkcmb_mayorisExit
  end
  object DBEdit1: TDBEdit
    Left = 160
    Top = 7
    Width = 360
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_mayoris
    TabOrder = 1
  end
  object DBEdit2: TDBEdit
    Left = 160
    Top = 31
    Width = 181
    Height = 21
    TabStop = False
    DataField = 'concep'
    DataSource = dts_facturas
    TabOrder = 2
  end
  object edt_letra: TdxDBCurrencyEdit
    Left = 69
    Top = 54
    Width = 90
    TabOrder = 3
    TabStop = False
    DataField = 'pagare'
    DataSource = dts_facturas
    DecimalPlaces = 0
    DisplayFormat = '0;-0'
    StoredValues = 0
  end
  object cmb_tipopago: TComboBox
    Left = 69
    Top = 77
    Width = 90
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 4
    Items.Strings = (
      'Efectivo'
      'Bonificación'
      'Devolución')
  end
  object edt_concepto: TEdit
    Left = 220
    Top = 100
    Width = 300
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 70
    TabOrder = 7
  end
  object DBEdit4: TDBEdit
    Left = 220
    Top = 55
    Width = 121
    Height = 21
    TabStop = False
    DataField = 'Fecha'
    DataSource = dts_facturas
    TabOrder = 8
  end
  object edt_importe: TdxCurrencyEdit
    Left = 69
    Top = 100
    Width = 90
    TabOrder = 6
    OnExit = edt_importeExit
  end
  object dxDBCurrencyEdit2: TdxDBCurrencyEdit
    Left = 399
    Top = 31
    Width = 121
    TabOrder = 9
    TabStop = False
    DataField = 'importe'
    DataSource = dts_facturas
  end
  object db_edit: TdxDBCurrencyEdit
    Left = 399
    Top = 55
    Width = 121
    TabOrder = 10
    TabStop = False
    DataField = 'Saldo'
    DataSource = dts_facturas
  end
  object DBEdit3: TDBEdit
    Left = 220
    Top = 77
    Width = 121
    Height = 21
    TabStop = False
    DataField = 'vence'
    DataSource = dts_facturas
    TabOrder = 11
  end
  object edt_referencia: TEdit
    Left = 399
    Top = 76
    Width = 121
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 70
    TabOrder = 5
  end
  object dbgrd_facturas: TdxDBGrid
    Left = 72
    Top = 136
    Width = 486
    Height = 90
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'IDMOV'
    SummaryGroups = <>
    SummarySeparator = ', '
    TabOrder = 12
    Visible = False
    DataSource = dts_facturas
    Filter.Criteria = {00000000}
    LookAndFeel = lfUltraFlat
    OptionsBehavior = [edgoAutoSearch, edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    OnCustomDraw = dbgrd_facturasCustomDraw
    object dbgrd_facturasFactura: TdxDBGridMaskColumn
      Caption = 'Factura'
      Width = 28
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DOCTO'
    end
    object dbgrd_facturasPAGARE: TdxDBGridMaskColumn
      Caption = 'Pagaré'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PAGARE'
    end
    object dbgrd_facturasFECHA: TdxDBGridDateColumn
      Caption = 'Fecha'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'FECHA'
      SummaryFooterType = cstCount
      SummaryFooterField = 'FECHA'
      SummaryFooterFormat = '0'
    end
    object dbgrd_facturasIMPORTE: TdxDBGridCurrencyColumn
      Caption = 'Importe'
      Width = 69
      BandIndex = 0
      RowIndex = 0
      FieldName = 'IMPORTE'
      SummaryFooterType = cstSum
      SummaryFooterField = 'IMPORTE'
      SummaryFooterFormat = '#,##0.00'
    end
    object dbgrd_facturasSALDO: TdxDBGridCurrencyColumn
      Caption = 'Saldo'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'SALDO'
    end
    object dbgrd_facturasVENCE: TdxDBGridMaskColumn
      Caption = 'Vence'
      Width = 50
      BandIndex = 0
      RowIndex = 0
      FieldName = 'VENCE'
    end
  end
  object dxDBCurrencyEdit1: TdxDBCurrencyEdit
    Left = 69
    Top = 30
    Width = 90
    TabOrder = 13
    TabStop = False
    DataField = 'DOCTO'
    DataSource = dts_facturas
    DecimalPlaces = 0
    DisplayFormat = '0;-0'
    StoredValues = 0
  end
  object qry_mayoris: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select * from mayoris where cia  = :CIA and status = '#39'A'#39' order b' +
        'y codigo'
      '')
    Left = 560
    Top = 32
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_mayoris: TDataSource
    DataSet = qry_mayoris
    Left = 528
    Top = 32
  end
  object dts_facturas: TDataSource
    DataSet = qry_facturas
    Left = 528
    Top = 64
  end
  object qry_facturas: TQuery
    AfterScroll = qry_facturasAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'a.*'
      'from movmay2  a where mayoris = :MAYORIS and saldo > 1'
      'and coa = '#39'C'#39' and cia  = :CIA order by docto, pagare'
      '')
    Left = 560
    Top = 64
    ParamData = <
      item
        DataType = ftString
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
end
