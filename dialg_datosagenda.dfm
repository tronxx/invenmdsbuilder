object dlg_datosagenda: Tdlg_datosagenda
  Left = 326
  Top = 241
  Width = 526
  Height = 112
  Caption = 'Datos del Almacén'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 33
    Width = 510
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
      OnClick = BitBtn1Click
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 510
    Height = 33
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 235
      Top = 16
      Width = 28
      Height = 13
      Caption = 'Ubica'
    end
    object Label3: TLabel
      Left = 8
      Top = 16
      Width = 22
      Height = 13
      Caption = 'Folio'
    end
    object Label4: TLabel
      Left = 96
      Top = 15
      Width = 30
      Height = 13
      Caption = 'Fecha'
    end
    object date_fecha: TDateTimePicker
      Left = 133
      Top = 11
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
      Left = 272
      Top = 11
      Width = 60
      Height = 21
      KeyField = 'UBICA'
      ListField = 'UBICA'
      ListSource = dts_almacen
      TabOrder = 2
    end
    object DBEdit1: TDBEdit
      Left = 334
      Top = 10
      Width = 162
      Height = 21
      TabStop = False
      DataField = 'DESCRI'
      DataSource = dts_almacen
      TabOrder = 1
    end
    object edt_folio: TdxDBCurrencyEdit
      Left = 35
      Top = 11
      Width = 50
      TabOrder = 3
      DecimalPlaces = 0
      DisplayFormat = '0;-0'
      StoredValues = 0
    end
  end
  object qry_almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idubiptovta, ubica, descri from inv_ubiptovta'
      'where cia = :CIA order by ubica')
    Left = 400
    Top = 32
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_almacen: TDataSource
    DataSet = qry_almacen
    Left = 432
    Top = 32
  end
end
